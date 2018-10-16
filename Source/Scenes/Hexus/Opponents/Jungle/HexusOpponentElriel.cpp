#include "HexusOpponentElriel.h"

const std::string HexusOpponentElriel::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_ELRIEL";
HexusOpponentElriel* HexusOpponentElriel::instance = nullptr;

HexusOpponentElriel* HexusOpponentElriel::getInstance()
{
	if (HexusOpponentElriel::instance == nullptr)
	{
		HexusOpponentElriel::instance = new HexusOpponentElriel();
	}

	return HexusOpponentElriel::instance;
}

HexusOpponentElriel::HexusOpponentElriel() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Jungle_Npcs_Elriel_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameJungle,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -48.0f),
	HexusOpponentElriel::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Binary5),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
		CardList::getInstance()->cardListByName->at(CardKeys::Addition),
	},
	HexusOpponentData::generateDeck(25, 0.1f,
		{
			CardList::getInstance()->cardListByName->at(CardKeys::Binary0),
			CardList::getInstance()->cardListByName->at(CardKeys::Hex0),
			CardList::getInstance()->cardListByName->at(CardKeys::Decimal0),
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		})
	)
{
}

HexusOpponentElriel::~HexusOpponentElriel()
{
}
