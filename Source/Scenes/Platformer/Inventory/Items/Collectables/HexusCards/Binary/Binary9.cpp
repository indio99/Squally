#include "Binary9.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Objects/Platformer/Collectables/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Hexus/Cards/Binary9.h"

using namespace cocos2d;

const std::string Binary9::SaveKeyBinary9 = "binary-9";

Binary9* Binary9::create()
{
	Binary9* instance = new Binary9();

	instance->autorelease();

	return instance;
}

Binary9::Binary9() : super(CurrencyInventory::create({{ IOU::getIdentifier(), 1 }}))
{
}

Binary9::~Binary9()
{
}

Item* Binary9::clone()
{
	return Binary9::create();
}

std::string Binary9::getItemName()
{
	return Binary9::SaveKeyBinary9;
}

LocalizedString* Binary9::getString()
{
	return Strings::Hexus_Cards_Binary9::create();
}

std::string Binary9::getIconResource()
{
	return ObjectResources::Collectables_Cards_CardBinary;
}

std::string Binary9::getSerializationKey()
{
	return Binary9::SaveKeyBinary9;
}