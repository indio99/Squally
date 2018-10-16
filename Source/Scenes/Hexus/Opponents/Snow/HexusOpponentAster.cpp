#include "HexusOpponentAster.h"

const std::string HexusOpponentAster::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_ASTER";
HexusOpponentAster* HexusOpponentAster::instance = nullptr;

HexusOpponentAster* HexusOpponentAster::getInstance()
{
	if (HexusOpponentAster::instance == nullptr)
	{
		HexusOpponentAster::instance = new HexusOpponentAster();
	}

	return HexusOpponentAster::instance;
}

HexusOpponentAster::HexusOpponentAster() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Snow_Npcs_Aster_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameIceCaps,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -40.0f),
	HexusOpponentAster::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.75f,
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

HexusOpponentAster::~HexusOpponentAster()
{
}
