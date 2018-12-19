////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "TikiGolem.h"

#include "Resources/EntityResources.h"

const std::string TikiGolem::MapKeyTikiGolem = "tiki-golem";

TikiGolem* TikiGolem::deserialize(cocos2d::ValueMap* initProperties)
{
	TikiGolem* instance = new TikiGolem(initProperties);

	instance->autorelease();

	return instance;
}

TikiGolem::TikiGolem(cocos2d::ValueMap* initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_SeaSharpCaverns_TikiGolem_Animations,
	PlatformerCollisionType::Enemy,
	cocos2d::Size(284.0f, 256.0f),
	1.0f,
	cocos2d::Vec2(0.0f, -112.0f))
{
}

TikiGolem::~TikiGolem()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////