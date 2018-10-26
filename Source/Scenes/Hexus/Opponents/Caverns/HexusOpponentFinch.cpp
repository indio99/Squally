#include "HexusOpponentFinch.h"

const std::string HexusOpponentFinch::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_FINCH";
HexusOpponentFinch* HexusOpponentFinch::instance = nullptr;

HexusOpponentFinch* HexusOpponentFinch::getInstance()
{
	if (HexusOpponentFinch::instance == nullptr)
	{
		HexusOpponentFinch::instance = new HexusOpponentFinch();
	}

	return HexusOpponentFinch::instance;
}

HexusOpponentFinch::HexusOpponentFinch() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Caverns_Npcs_Finch_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameCaverns,
	0.9f,
	Vec2(-32.0f, -64.0f),
	Vec2(-16.0f, -32.0f),
	HexusOpponentFinch::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Shadow,
	HexusOpponentData::generateReward(0.42f),
	HexusOpponentData::generateDeck(25, 0.42f,
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

HexusOpponentFinch::~HexusOpponentFinch()
{
}