#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentReaper : public HexusOpponentData
{
public:
	static HexusOpponentReaper* getInstance();

private:
	HexusOpponentReaper();
	~HexusOpponentReaper();

	static const std::string OpponentSaveKey;
	static HexusOpponentReaper* instance;
};