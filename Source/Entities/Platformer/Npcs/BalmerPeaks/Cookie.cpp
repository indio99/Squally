////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "Cookie.h"

#include "Resources/EntityResources.h"

const std::string Cookie::MapKeyCookie = "cookie";

Cookie* Cookie::deserialize(cocos2d::ValueMap& initProperties)
{
	Cookie* instance = new Cookie(initProperties);

	instance->autorelease();

	return instance;
}

Cookie::Cookie(cocos2d::ValueMap& initProperties) : NpcBase(initProperties,
	EntityResources::Npcs_BalmerPeaks_Cookie_Animations,
	EntityResources::Npcs_BalmerPeaks_Cookie_Emblem,
	PlatformerCollisionType::FriendlyNpc,
	cocos2d::Size(112.0f, 160.0f),
	0.9f,
	cocos2d::Vec2(0.0f, 0.0f),
	10,
	10)
{
}

Cookie::~Cookie()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////