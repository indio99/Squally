#include "SnailShell.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string SnailShell::SaveKeySnailShell = "snail-shell";

SnailShell* SnailShell::create()
{
	SnailShell* instance = new SnailShell();

	instance->autorelease();

	return instance;
}

SnailShell::SnailShell() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), ItemStats(
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

SnailShell::~SnailShell()
{
}

Item* SnailShell::clone()
{
	return SnailShell::create();
}

std::string SnailShell::getItemName()
{
	return SnailShell::SaveKeySnailShell;
}

LocalizedString* SnailShell::getString()
{
	return Strings::Items_Equipment_Gear_Hats_SantaHat::create();
}

std::string SnailShell::getIconResource()
{
	return ObjectResources::Items_Equipment_Gear_Hats_SnailShell;
}

std::string SnailShell::getSerializationKey()
{
	return SnailShell::SaveKeySnailShell;
}

Vec2 SnailShell::getDisplayOffset()
{
	return Vec2(12.0f, -24.0f);
}