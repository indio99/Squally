#include "EntityCombatBehaviorGroup.h"

#include "Engine/Maps/GameObject.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Collision/EntityCollisionBehaviorGroup.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Combat/EntityAttackBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Combat/EntityBuffBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Combat/EntityDropTableBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Developer/EntityDeveloperBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/EntitySelectionBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Items/EntityInventoryBehavior.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Stats/EntityStatsBehaviorGroup.h"

using namespace cocos2d;

const std::string EntityCombatBehaviorGroup::MapKeyAttachedBehavior = "entity-collisions";

EntityCombatBehaviorGroup* EntityCombatBehaviorGroup::create(GameObject* owner)
{
	EntityCombatBehaviorGroup* instance = new EntityCombatBehaviorGroup(owner);

	instance->autorelease();

	return instance;
}

EntityCombatBehaviorGroup::EntityCombatBehaviorGroup(GameObject* owner) : super(owner, {
	EntityAttackBehavior::create(owner),
	EntityBuffBehavior::create(owner),
	EntityDropTableBehavior::create(owner),
	EntitySelectionBehavior::create(owner),
	EntityDeveloperBehavior::create(owner),
	EntityStatsBehaviorGroup::create(owner),
	EntityInventoryBehavior::create(owner),
	})
{
}

EntityCombatBehaviorGroup::~EntityCombatBehaviorGroup()
{
}

void EntityCombatBehaviorGroup::onLoad()
{
}
