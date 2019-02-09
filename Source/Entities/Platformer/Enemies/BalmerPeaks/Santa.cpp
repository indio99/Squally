////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "Santa.h"

#include "Resources/EntityResources.h"

const std::string Santa::MapKeySanta = "santa";

Santa* Santa::deserialize(cocos2d::ValueMap& initProperties)
{
	Santa* instance = new Santa(initProperties);

	instance->autorelease();

	return instance;
}

Santa::Santa(cocos2d::ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_BalmerPeaks_Santa_Animations,
	EntityResources::Enemies_BalmerPeaks_Santa_Emblem,
	PlatformerCollisionType::Enemy,
	cocos2d::Size(420.0f, 452.0f),
	0.7f,
	cocos2d::Vec2(0.0f, 0.0f),
	10,
	10)
{
}

Santa::~Santa()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////