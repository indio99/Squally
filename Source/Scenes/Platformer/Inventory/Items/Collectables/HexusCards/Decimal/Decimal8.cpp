#include "Decimal8.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Objects/Platformer/Collectables/IOU.h"

#include "Resources/ObjectResources.h"

#include "Strings/Hexus/Cards/Decimal8.h"

using namespace cocos2d;

const std::string Decimal8::SaveKeyDecimal8 = "decimal-8";

Decimal8* Decimal8::create()
{
	Decimal8* instance = new Decimal8();

	instance->autorelease();

	return instance;
}

Decimal8::Decimal8() : super(CurrencyInventory::create({{ IOU::getIdentifier(), 1 }}))
{
}

Decimal8::~Decimal8()
{
}

Item* Decimal8::clone()
{
	return Decimal8::create();
}

std::string Decimal8::getItemName()
{
	return Decimal8::SaveKeyDecimal8;
}

LocalizedString* Decimal8::getString()
{
	return Strings::Hexus_Cards_Decimal8::create();
}

std::string Decimal8::getIconResource()
{
	return ObjectResources::Collectables_Cards_CardDecimal;
}

std::string Decimal8::getSerializationKey()
{
	return Decimal8::SaveKeyDecimal8;
}