#include "Water.h"

#include "cocos/base/CCValue.h"

#include "Engine/Physics/CollisionObject.h"
#include "Engine/Physics/Liquid/LiquidNode.h"
#include "Engine/Utils/GameUtils.h"
#include "Scenes/Platformer/Level/Physics/PlatformerCollisionType.h"

#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string Water::MapKeyWater = "water";
const float Water::WaterGravity = 0.0f;

Water* Water::create(ValueMap& initProperties)
{
	Water* instance = new Water(initProperties);

	instance->autorelease();

	return instance;
}

Water::Water(ValueMap& initProperties) : super(initProperties)
{
	this->waterSize = Size(this->properties.at(GameObject::MapKeyWidth).asFloat(), this->properties.at(GameObject::MapKeyHeight).asFloat());
	this->elapsed = 0.0f;
	this->water = LiquidNode::create(this->waterSize, 192.0f);

	std::string customCollison = GameUtils::getKeyOrDefault(this->properties, CollisionObject::MapKeyTypeCollision, Value("")).asString();

	if (customCollison == "")
	{
		this->waterCollision = CollisionObject::create(PhysicsBody::createBox(this->waterSize), (CollisionType)PlatformerCollisionType::Water, false, false);
	}
	else
	{
		this->waterCollision = CollisionObject::create(PhysicsBody::createBox(this->waterSize), customCollison, false, false);
	}
	
	this->addChild(this->water);
	this->addChild(this->waterCollision);
}

Water::~Water()
{
}

void Water::onEnter()
{
	super::onEnter();
	
	this->water->splash(42, -128.0f);

	this->scheduleUpdate();
}

void Water::update(float dt)
{
	super::update(dt);

	this->elapsed += dt;

	if (this->elapsed > 5.0f)
	{
		this->elapsed = 0.0f;
	}
}

void Water::initializePositions()
{
	super::initializePositions();
}

void Water::initializeListeners()
{
	super::initializeListeners();

	this->waterCollision->setContactUpdateCallback(CC_CALLBACK_2(Water::applyWaterForce, this));

	this->waterCollision->whenCollidesWith({ (int)PlatformerCollisionType::Player, (int)PlatformerCollisionType::Physics }, [=](CollisionObject::CollisionData collisionData)
	{
		// Speed is applied in the update applyWaterForce

		return CollisionObject::CollisionResult::DoNothing;
	});
}

void Water::applyWaterForce(const std::vector<CollisionObject*>& targets, float dt)
{
	for (auto it = targets.begin(); it != targets.end(); it++)
	{
		(*it)->setVelocity((*it)->getVelocity() + Vec2(0.0f, Water::WaterGravity * dt));
	}
}
