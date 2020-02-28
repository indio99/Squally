#include "AcolytesCap.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string AcolytesCap::SaveKeyAcolytesCap = "acolytes-cap";

AcolytesCap* AcolytesCap::create()
{
	AcolytesCap* instance = new AcolytesCap();

	instance->autorelease();

	return instance;
}

AcolytesCap::AcolytesCap() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), ItemStats(
	// Health
	0,
	// Mana
	0,
	// Attack
	0,
	// Armor
	0,
	// Speed
	0.05f
))
{
}

AcolytesCap::~AcolytesCap()
{
}

Item* AcolytesCap::clone()
{
	return AcolytesCap::create();
}

std::string AcolytesCap::getItemName()
{
	return AcolytesCap::SaveKeyAcolytesCap;
}

LocalizedString* AcolytesCap::getString()
{
	return Strings::Items_Equipment_Gear_Hats_SantaHat::create();
}

std::string AcolytesCap::getIconResource()
{
	return ObjectResources::Items_Equipment_Gear_Hats_AcolytesCap;
}

std::string AcolytesCap::getSerializationKey()
{
	return AcolytesCap::SaveKeyAcolytesCap;
}

Vec2 AcolytesCap::getDisplayOffset()
{
	return Vec2(12.0f, -24.0f);
}