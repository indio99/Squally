#include "GuanoBehaviorGroup.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"

#include "Engine/Maps/GameObject.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Friendly/FriendlyBehaviorGroup.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Helpers/FollowMovementBehavior.h"

using namespace cocos2d;

const std::string GuanoBehaviorGroup::MapKeyAttachedBehavior = "guano";

GuanoBehaviorGroup* GuanoBehaviorGroup::create(GameObject* owner)
{
	GuanoBehaviorGroup* instance = new GuanoBehaviorGroup(owner);

	instance->autorelease();

	return instance;
}

GuanoBehaviorGroup::GuanoBehaviorGroup(GameObject* owner) : super(owner, {
	FriendlyBehaviorGroup::create(owner),
	FollowMovementBehavior::create(owner),
	})
{
}

GuanoBehaviorGroup::~GuanoBehaviorGroup()
{
}

void GuanoBehaviorGroup::onLoad()
{
}
