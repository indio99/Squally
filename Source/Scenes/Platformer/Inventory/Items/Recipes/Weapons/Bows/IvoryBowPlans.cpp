#include "IvoryBowPlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string IvoryBowPlans::SaveKeyIvoryBowPlans = "ivory-bow-plans";

IvoryBowPlans* IvoryBowPlans::create()
{
	IvoryBowPlans* instance = new IvoryBowPlans();

	instance->autorelease();

	return instance;
}

IvoryBowPlans::IvoryBowPlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

IvoryBowPlans::~IvoryBowPlans()
{
}

Item* IvoryBowPlans::craft()
{
	return IvoryBow::create();
}

std::vector<std::tuple<Item*, int>> IvoryBowPlans::getReagentsInternal()
{
	return
	{
		{ Wood::create(), 2 },
		{ Iron::create(), 4 },
	};
}

Item* IvoryBowPlans::clone()
{
	return IvoryBowPlans::create();
}

std::string IvoryBowPlans::getItemName()
{
	return IvoryBowPlans::SaveKeyIvoryBowPlans;
}

LocalizedString* IvoryBowPlans::getString()
{
	return Strings::Items_Equipment_Weapons_Bows_IvoryBow::create();
}

std::string IvoryBowPlans::getIconResource()
{
	return ItemResources::Misc_SCROLL_1;
}

std::string IvoryBowPlans::getCraftedItemIconResource()
{
	return ItemResources::Equipment_Weapons_Bows_IvoryBow;
}

std::string IvoryBowPlans::getSerializationKey()
{
	return IvoryBowPlans::SaveKeyIvoryBowPlans;
}