#include "HexusOpponentHorus.h"

const std::string HexusOpponentHorus::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_HORUS";
HexusOpponentHorus* HexusOpponentHorus::instance = nullptr;

HexusOpponentHorus* HexusOpponentHorus::getInstance()
{
	if (HexusOpponentHorus::instance == nullptr)
	{
		HexusOpponentHorus::instance = new HexusOpponentHorus();
	}

	return HexusOpponentHorus::instance;
}

HexusOpponentHorus::HexusOpponentHorus() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Ruins_Npcs_Horus_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameRuins,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -64.0f),
	HexusOpponentHorus::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.4f,
		{
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalOr),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalXor),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		})
	)
{
}

HexusOpponentHorus::~HexusOpponentHorus()
{
}
