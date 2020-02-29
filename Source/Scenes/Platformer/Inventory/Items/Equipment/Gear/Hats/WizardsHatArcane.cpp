#include "WizardsHatArcane.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string WizardsHatArcane::SaveKeyWizardsHatArcane = "wizards-hat-arcane";

WizardsHatArcane* WizardsHatArcane::create()
{
	WizardsHatArcane* instance = new WizardsHatArcane();

	instance->autorelease();

	return instance;
}

WizardsHatArcane::WizardsHatArcane() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), ItemStats(
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

WizardsHatArcane::~WizardsHatArcane()
{
}

Item* WizardsHatArcane::clone()
{
	return WizardsHatArcane::create();
}

std::string WizardsHatArcane::getItemName()
{
	return WizardsHatArcane::SaveKeyWizardsHatArcane;
}

LocalizedString* WizardsHatArcane::getString()
{
	return Strings::Items_Equipment_Gear_Hats_SantaHat::create();
}

std::string WizardsHatArcane::getIconResource()
{
	return ObjectResources::Items_Equipment_Gear_Hats_WizardsHatArcane;
}

std::string WizardsHatArcane::getSerializationKey()
{
	return WizardsHatArcane::SaveKeyWizardsHatArcane;
}

Vec2 WizardsHatArcane::getDisplayOffset()
{
	return Vec2(-22.0f, -8.0f);
}
