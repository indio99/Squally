#include "JoustingHelmet.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string JoustingHelmet::SaveKeyJoustingHelmet = "jousting-helmet";

JoustingHelmet* JoustingHelmet::create()
{
	JoustingHelmet* instance = new JoustingHelmet();

	instance->autorelease();

	return instance;
}

JoustingHelmet::JoustingHelmet() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}), ItemStats(
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

JoustingHelmet::~JoustingHelmet()
{
}

Item* JoustingHelmet::clone()
{
	return JoustingHelmet::create();
}

std::string JoustingHelmet::getItemName()
{
	return JoustingHelmet::SaveKeyJoustingHelmet;
}

LocalizedString* JoustingHelmet::getString()
{
	return Strings::Items_Equipment_Gear_Hats_SantaHat::create();
}

std::string JoustingHelmet::getIconResource()
{
	return ObjectResources::Items_Equipment_Gear_Hats_JoustingHelmet;
}

std::string JoustingHelmet::getSerializationKey()
{
	return JoustingHelmet::SaveKeyJoustingHelmet;
}

Vec2 JoustingHelmet::getDisplayOffset()
{
	return Vec2(12.0f, -24.0f);
}