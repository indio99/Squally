#include "DemonicBowPlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ItemResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string DemonicBowPlans::SaveKeyDemonicBowPlans = "demonic-bow-plans";

DemonicBowPlans* DemonicBowPlans::create()
{
	DemonicBowPlans* instance = new DemonicBowPlans();

	instance->autorelease();

	return instance;
}

DemonicBowPlans::DemonicBowPlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

DemonicBowPlans::~DemonicBowPlans()
{
}

Item* DemonicBowPlans::craft()
{
	return DemonicBow::create();
}

std::vector<std::tuple<Item*, int>> DemonicBowPlans::getReagentsInternal()
{
	return
	{
		{ Quartz::create(), 4 },
		{ Emerald::create(), 2 },
		{ Sapphire::create(), 2 },
		{ Iron::create(), 4 },
		{ Coal::create(), 4 },
	};
}

Item* DemonicBowPlans::clone()
{
	return DemonicBowPlans::create();
}

std::string DemonicBowPlans::getItemName()
{
	return DemonicBowPlans::SaveKeyDemonicBowPlans;
}

LocalizedString* DemonicBowPlans::getString()
{
	return Strings::Items_Equipment_Weapons_Bows_DemonicBow::create();
}

std::string DemonicBowPlans::getIconResource()
{
	return ItemResources::Misc_SCROLL_1;
}

std::string DemonicBowPlans::getCraftedItemIconResource()
{
	return ItemResources::Equipment_Weapons_Bows_DemonicBow;
}

std::string DemonicBowPlans::getSerializationKey()
{
	return DemonicBowPlans::SaveKeyDemonicBowPlans;
}