////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

#include "Entities/Platformer/NpcBase.h"

class Xenon : public NpcBase
{
public:
	static Xenon* deserialize(cocos2d::ValueMap* initProperties);

	static const std::string MapKeyXenon;

private:
	Xenon(cocos2d::ValueMap* initProperties);
	~Xenon();
};