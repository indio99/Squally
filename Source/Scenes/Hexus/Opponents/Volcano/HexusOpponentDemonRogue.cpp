#include "HexusOpponentDemonRogue.h"

const std::string HexusOpponentDemonRogue::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_DEMON_GRUNT";
HexusOpponentDemonRogue* HexusOpponentDemonRogue::instance = nullptr;

HexusOpponentDemonRogue* HexusOpponentDemonRogue::getInstance()
{
	if (HexusOpponentDemonRogue::instance == nullptr)
	{
		HexusOpponentDemonRogue::instance = new HexusOpponentDemonRogue();
	}

	return HexusOpponentDemonRogue::instance;
}

HexusOpponentDemonRogue::HexusOpponentDemonRogue() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Volcano_Enemies_DemonRogue_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameVolcano,
	0.85f,
	Vec2(-48.0f, -48.0f),
	Vec2(-16.0f, -32.0f),
	HexusOpponentDemonRogue::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	HexusOpponentData::generateReward(0.725f),
	HexusOpponentData::generateDeck(25, 0.725f,
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

HexusOpponentDemonRogue::~HexusOpponentDemonRogue()
{
}