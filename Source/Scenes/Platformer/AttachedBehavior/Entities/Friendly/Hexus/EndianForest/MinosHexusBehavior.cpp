#include "MinosHexusBehavior.h"

#include "Objects/Platformer/ItemPools/HexusPools/EndianForest/HexusPoolEFGeneric.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Friendly/Hexus/EndianForest/EFHexusConfig.h"

#include "Resources/HexusResources.h"
#include "Resources/SoundResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string MinosHexusBehavior::MapKey = "minos-hexus";

MinosHexusBehavior* MinosHexusBehavior::create(GameObject* owner)
{
	MinosHexusBehavior* instance = new MinosHexusBehavior(owner);

	instance->autorelease();

	return instance;
}

MinosHexusBehavior::MinosHexusBehavior(GameObject* owner) : super(owner, SoundResources::Platformer_Entities_Generic_ChatterShort1)
{
}

MinosHexusBehavior::~MinosHexusBehavior()
{
}

MinMaxPool* MinosHexusBehavior::generateReward()
{
	return HexusPoolEFGeneric::create();
}

std::string MinosHexusBehavior::getWinLossSaveKey()
{
	return MinosHexusBehavior::MapKey;
}

std::string MinosHexusBehavior::getBackgroundResource()
{
	return HexusResources::Menus_HexusFrameCastleValgrind;
}

std::vector<CardData*> MinosHexusBehavior::generateDeck()
{
	const float LocalOrder = 2.0f / EFHexusConfig::MaxEntities;

	return HexusOpponentData::generateDeck(25, LocalOrder * EFHexusConfig::ZoneOrder,
	{
		CardList::getInstance()->cardListByName[CardKeys::Binary0],
		CardList::getInstance()->cardListByName[CardKeys::Decimal0],
		CardList::getInstance()->cardListByName[CardKeys::Hex0],
	});
}

StateOverride* MinosHexusBehavior::getStateOverride()
{
	return nullptr;
}

std::vector<TutorialBase*> MinosHexusBehavior::getTutorials()
{
	return { };
}
