#include "HexusOpponentLucifer.h"

const std::string HexusOpponentLucifer::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_LUCIFER";
HexusOpponentLucifer* HexusOpponentLucifer::instance = nullptr;

HexusOpponentLucifer* HexusOpponentLucifer::getInstance()
{
	if (HexusOpponentLucifer::instance == nullptr)
	{
		HexusOpponentLucifer::instance = new HexusOpponentLucifer();
	}

	return HexusOpponentLucifer::instance;
}

HexusOpponentLucifer::HexusOpponentLucifer() : HexusOpponentData(
	EntityResources::Environment_Volcano_Npcs_Lucifer_Animations,
	UIResources::Menus_MinigamesMenu_Hexus_HexusFrameVolcano,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -32.0f),
	HexusOpponentLucifer::OpponentSaveKey,
	HexusOpponentData::Strategy::Random,
	Card::CardStyle::Earth,
	HexusOpponentData::generateReward(0.76f),
	HexusOpponentData::generateDeck(25, 0.76f,
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

HexusOpponentLucifer::~HexusOpponentLucifer()
{
}
