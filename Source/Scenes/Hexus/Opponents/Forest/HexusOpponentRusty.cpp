#include "HexusOpponentRusty.h"

const std::string HexusOpponentRusty::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_RUSTY";
HexusOpponentRusty* HexusOpponentRusty::instance = nullptr;

HexusOpponentRusty* HexusOpponentRusty::getInstance()
{
	if (HexusOpponentRusty::instance == nullptr)
	{
		HexusOpponentRusty::instance = new HexusOpponentRusty();
	}

	return HexusOpponentRusty::instance;
}

HexusOpponentRusty::HexusOpponentRusty() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Forest_Npcs_Rusty_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameForest,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -32.0f),
	HexusOpponentRusty::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.45f,
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

HexusOpponentRusty::~HexusOpponentRusty()
{
}
