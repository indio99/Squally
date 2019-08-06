#include "EntityCollisionBehaviors.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Physics/EngineCollisionTypes.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Resources/EntityResources.h"

using namespace cocos2d;

const std::string EntityCollisionBehaviors::MapKeyAttachedBehavior = "entity-collisions";
const float EntityCollisionBehaviors::GroundCollisionPadding = 28.0f;

EntityCollisionBehaviors* EntityCollisionBehaviors::create(GameObject* owner, std::string attachedBehaviorArgs)
{
	EntityCollisionBehaviors* instance = new EntityCollisionBehaviors(owner, attachedBehaviorArgs);

	instance->autorelease();

	return instance;
}

EntityCollisionBehaviors::EntityCollisionBehaviors(GameObject* owner, std::string attachedBehaviorArgs) : super(owner, attachedBehaviorArgs)
{
	this->entity = static_cast<PlatformerEntity*>(owner);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}
}

EntityCollisionBehaviors::~EntityCollisionBehaviors()
{
}

void EntityCollisionBehaviors::onLoad()
{
	this->groundCollision = CollisionObject::create(
		CollisionObject::createCapsulePolygon(
			Size(std::max((this->entity->entitySize).width - EntityCollisionBehaviors::GroundCollisionPadding * 2.0f, 8.0f), 40.0f),
			1.0f,
			PlatformerEntity::CapsuleRadius
		),
		(int)PlatformerCollisionType::GroundDetector,
		false,
		false
	);

	this->groundCollision->getPhysicsBody()->setPositionOffset(Vec2(0.0f, -this->entity->hoverHeight / 2.0f + PlatformerEntity::GroundCollisionOffset + this->calculateGhettoOffsetFix()));
	
	this->entity->addChild(this->groundCollision);

	this->entity->movementCollision->whenCollidesWith({ (int)PlatformerCollisionType::Solid, (int)PlatformerCollisionType::Physics }, [=](CollisionObject::CollisionData collisionData)
	{	
		return CollisionObject::CollisionResult::CollideWithPhysics;
	});

	this->entity->movementCollision->whenCollidesWith({ (int)PlatformerCollisionType::PassThrough }, [=](CollisionObject::CollisionData collisionData)
	{
		// No collision when not standing on anything, or if already on a different platform
		if (this->groundCollision->getCurrentCollisions().empty() || this->isStandingOnSomethingOtherThan(collisionData.other))
		{
			return CollisionObject::CollisionResult::DoNothing;
		}

		return CollisionObject::CollisionResult::CollideWithPhysics;
	});

	this->entity->movementCollision->whenCollidesWith({ (int)PlatformerCollisionType::Water, }, [=](CollisionObject::CollisionData collisionData)
	{
		this->entity->movementCollision->setGravityEnabled(false);
		this->entity->controlState = PlatformerEntity::ControlState::Swimming;
		this->entity->movementCollision->setVerticalDampening(PlatformerEntity::SwimVerticalDrag);

		// Clear current animation
		this->entity->animationNode->playAnimation("Idle");
		
		return CollisionObject::CollisionResult::DoNothing;
	});

	this->entity->movementCollision->whenStopsCollidingWith({ (int)PlatformerCollisionType::Water, }, [=](CollisionObject::CollisionData collisionData)
	{
		this->entity->movementCollision->setGravityEnabled(true);
		this->entity->controlState = PlatformerEntity::ControlState::Normal;
		this->entity->movementCollision->setVerticalDampening(CollisionObject::DefaultVerticalDampening);

		// Animate jumping out of water
		if (this->entity->movementCollision->getVelocity().y > 0.0f)
		{
			// Give a velocity boost for jumping out of water
			this->entity->movementCollision->setVelocity(Vec2(this->entity->movementCollision->getVelocity().x, PlatformerEntity::JumpVelocity));

			this->entity->animationNode->playAnimation("Jump");
		}
		
		return CollisionObject::CollisionResult::DoNothing;
	});

	this->groundCollision->whenCollidesWith({ (int)PlatformerCollisionType::Solid, (int)PlatformerCollisionType::PassThrough, (int)PlatformerCollisionType::Physics }, [=](CollisionObject::CollisionData collisionData)
	{
		// Clear current animation
		if (!this->entity->isDead() && this->entity->movementCollision->getVelocity().y <= 0.0f)
		{
			this->entity->animationNode->playAnimation("Idle");
		}

		return CollisionObject::CollisionResult::DoNothing;
	});

	this->groundCollision->whenStopsCollidingWith({ (int)EngineCollisionTypes::Intersection }, [=](CollisionObject::CollisionData collisionData)
	{
		return CollisionObject::CollisionResult::DoNothing;
	});

	this->groundCollision->whenStopsCollidingWith({ (int)PlatformerCollisionType::Solid, (int)PlatformerCollisionType::PassThrough, (int)PlatformerCollisionType::Physics }, [=](CollisionObject::CollisionData collisionData)
	{
		return CollisionObject::CollisionResult::DoNothing;
	});

	this->entity->leftCollision->whenCollidesWith({ (int)PlatformerCollisionType::Solid }, [=](CollisionObject::CollisionData collisionData)
	{	
		return CollisionObject::CollisionResult::DoNothing;
	});

	this->entity->rightCollision->whenCollidesWith({ (int)PlatformerCollisionType::Solid }, [=](CollisionObject::CollisionData collisionData)
	{	
		return CollisionObject::CollisionResult::DoNothing;
	});
}

bool EntityCollisionBehaviors::isStandingOnSomethingOtherThan(CollisionObject* collisonObject)
{
	Node* currentCollisionGroup = collisonObject->getParent();
	std::vector<CollisionObject*> groundCollisions = this->groundCollision->getCurrentCollisions();

	// Special case when standing on an intersection -- always collide with the non-owner of that intersection point (the lower platform)
	for (auto it = groundCollisions.begin(); it != groundCollisions.end(); it++)
	{
		switch((*it)->getCollisionType())
		{
			case (int)EngineCollisionTypes::Intersection:
			{
				return currentCollisionGroup == (*it)->getParent();
			}
			default:
			{
				break;
			}
		}
	}

	// Greedy search for the oldest collision. This works out as being the object that is the true "ground".
	for (auto it = groundCollisions.begin(); it != groundCollisions.end(); it++)
	{
		switch((*it)->getCollisionType())
		{
			case (int)PlatformerCollisionType::Solid:
			case (int)PlatformerCollisionType::PassThrough:
			{
				// Do a parent check because multiple collison objects can be nested under the same macro-object (ie terrain segments)
				if ((*it)->getParent() != currentCollisionGroup)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			default:
			{
				break;
			}
		}
	}

	return false;
}

void EntityCollisionBehaviors::update(float dt)
{
	super::update(dt);

	this->entity->setState(StateKeys::IsOnGround, Value(!this->groundCollision->getCurrentCollisions().empty()));
}

float EntityCollisionBehaviors::calculateGhettoOffsetFix()
{
	if (dynamic_cast<Squally*>(this->entity) != nullptr)
	{
		return 24.0f;
	}

	return 0.0f;
}