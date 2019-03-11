//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED. ONLY EDIT NON-GENERATED SECTIONS. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Gecko.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

#include "Resources/EntityResources.h"
#include "Resources/UIResources.h"

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////A////A////A////A////A////A////A////A////A////A/

////B////B////B////B////B////B////B////B////B////B/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

using namespace cocos2d;

const std::string Gecko::MapKeyGecko = "gecko";
HexusOpponentData* Gecko::HexusOpponentDataInstance = nullptr;
const std::string Gecko::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_GECKO";

Gecko* Gecko::deserialize(ValueMap& initProperties)
{
	Gecko* instance = new Gecko(initProperties);

	instance->autorelease();

	return instance;
}

Gecko::Gecko(ValueMap& initProperties) : PlatformerEntity(initProperties,
	EntityResources::Helpers_SeaSharpCaverns_Gecko_Animations,
	EntityResources::Helpers_SeaSharpCaverns_Gecko_Emblem,
	PlatformerCollisionType::FriendlyNpc,
	Size(224.0f, 440.0f),
	0.3f,
	Vec2(0.0f, 0.0f),
	10,
	10)
{
	this->hexusOpponentData = Gecko::getHexusOpponentData();

	///////////////////////////////////////////////////
	// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
	////Y////Y////Y////Y////Y////Y////Y////Y////Y////Y/

	////Z////Z////Z////Z////Z////Z////Z////Z////Z////Z/
	// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
	///////////////////////////////////////////////////
}

Gecko::~Gecko()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

Vec2 Gecko::getAvatarFrameOffset()
{
	return Vec2(0.0f, 0.0f);
}

HexusOpponentData* Gecko::getHexusOpponentData()
{
	if (Gecko::HexusOpponentDataInstance == nullptr)
	{
		Gecko::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Helpers_SeaSharpCaverns_Gecko_Animations,
			UIResources::Menus_MinigamesMenu_Hexus_HexusFrameCastle,
			0.3f,
			Vec2(0.0f, 0.0f),
			Vec2(0.0f, 0.0f),
			Gecko::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Shadow,
			HexusOpponentData::generateReward(0.62f),
			HexusOpponentData::generateDeck(25, 0.62f,
			{
				CardList::getInstance()->cardListByName.at(CardKeys::Addition),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalAnd),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalOr),
				CardList::getInstance()->cardListByName.at(CardKeys::LogicalXor),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftLeft),
				CardList::getInstance()->cardListByName.at(CardKeys::ShiftRight),
			})
		);
	}

	return Gecko::HexusOpponentDataInstance;
}