////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "PenguinWarrior.h"

#include "Resources/EntityResources.h"

const std::string PenguinWarrior::MapKeyPenguinWarrior = "penguin-warrior";

PenguinWarrior* PenguinWarrior::deserialize(cocos2d::ValueMap& initProperties)
{
	PenguinWarrior* instance = new PenguinWarrior(initProperties);

	instance->autorelease();

	return instance;
}

PenguinWarrior::PenguinWarrior(cocos2d::ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_BalmerPeaks_PenguinWarrior_Animations,
	EntityResources::Enemies_BalmerPeaks_PenguinWarrior_Emblem,
	PlatformerCollisionType::Enemy,
	cocos2d::Size(212.0f, 296.0f),
	0.7f,
	cocos2d::Vec2(0.0f, 0.0f),
	10,
	10)
{
}

PenguinWarrior::~PenguinWarrior()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////