#include "TopHat.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string TopHat::SaveKeyTopHat = "top-hat";

TopHat* TopHat::create()
{
	TopHat* instance = new TopHat();

	instance->autorelease();

	return instance;
}

TopHat::TopHat() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), ItemStats(
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

TopHat::~TopHat()
{
}

Item* TopHat::clone()
{
	return TopHat::create();
}

std::string TopHat::getItemName()
{
	return TopHat::SaveKeyTopHat;
}

LocalizedString* TopHat::getString()
{
	return Strings::Items_Equipment_Gear_Hats_SantaHat::create();
}

std::string TopHat::getIconResource()
{
	return ObjectResources::Items_Equipment_Gear_Hats_TopHat;
}

std::string TopHat::getSerializationKey()
{
	return TopHat::SaveKeyTopHat;
}

Vec2 TopHat::getDisplayOffset()
{
	return Vec2(12.0f, -24.0f);
}