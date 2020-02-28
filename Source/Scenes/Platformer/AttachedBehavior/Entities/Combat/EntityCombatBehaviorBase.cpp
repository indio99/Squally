#include "EntityCombatBehaviorBase.h"

#include "Engine/Inventory/Inventory.h"
#include "Engine/Inventory/Item.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Items/EntityInventoryBehavior.h"
#include "Scenes/Platformer/Level/Combat/Attacks/Entities/Enemies/BasicSlash.h"
#include "Scenes/Platformer/Inventory/EquipmentInventory.h"
#include "Scenes/Platformer/Inventory/Items/Equipment/Equipable.h"
#include "Scenes/Platformer/Inventory/Items/Consumables/Health/RestorePotion/RestorePotion.h"

#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Resources/UIResources.h"

#include "Events/CombatEvents.h"

using namespace cocos2d;

EntityCombatBehaviorBase::EntityCombatBehaviorBase(GameObject* owner) : super(owner)
{
	this->entity = dynamic_cast<PlatformerEntity*>(owner);
	this->timelineSpeed = 1.0f;
	this->bonusArmor = 0;
	this->bonusAttack = 0;
	this->bonusSpeed = 0.0f;

	if (this->entity == nullptr)
	{
		this->invalidate();
	}
}

EntityCombatBehaviorBase::~EntityCombatBehaviorBase()
{
}

void EntityCombatBehaviorBase::setTimelineSpeed(float timelineSpeed)
{
	this->timelineSpeed = timelineSpeed;
}

float EntityCombatBehaviorBase::getTimelineSpeed()
{
	return this->timelineSpeed + this->bonusSpeed;
}

void EntityCombatBehaviorBase::onLoad()
{
	/*
	this->addEventListener(EventListenerCustom::create(CombatEvents::EventEntityBuffsModifyDamageOrHealingTaken, [=](EventCustom* eventCustom)
	{
		CombatEvents::BeforeDamageOrHealingTakenArgs* args = static_cast<CombatEvents::BeforeDamageOrHealingTakenArgs*>(eventCustom->getUserData());

		if (args != nullptr && args->target == this->entity && !args->isHandled())
		{
			this->onBeforeDamageTaken(args->damageOrHealing, args->blocked, [=](){ args->handle(); });
		}
	}));*/

	this->entity->watchForAttachedBehavior<EntityInventoryBehavior>([=](EntityInventoryBehavior* inventoryBehavior)
	{
		for (auto next : inventoryBehavior->getEquipmentInventory()->getEquipment())
		{
			this->bonusArmor += next->getItemStats().armorBonus;
			this->bonusAttack += next->getItemStats().attackBonus;
			this->bonusSpeed += next->getItemStats().speedBonus;
		}
	});
}

void EntityCombatBehaviorBase::onBeforeDamageTaken(int* damageOrHealing, bool* blocked, std::function<void()> handleCallback)
{
	if (damageOrHealing >= 0)
	{
		return;
	}

	*damageOrHealing -= this->bonusArmor;
}

void EntityCombatBehaviorBase::onBeforeDamageDelt(int* damageOrHealing, std::function<void()> handleCallback)
{
	*damageOrHealing += this->bonusAttack;
}