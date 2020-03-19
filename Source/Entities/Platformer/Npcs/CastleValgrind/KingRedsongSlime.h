#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class HexusOpponentData;
class LocalizedString;

class KingRedsongSlime : public PlatformerFriendly
{
public:
	static KingRedsongSlime* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;
	static HexusOpponentData* getHexusOpponentData();

	static const std::string MapKey;

protected:
	KingRedsongSlime(cocos2d::ValueMap& properties);
	virtual ~KingRedsongSlime();

private:
	typedef PlatformerFriendly super;

	static HexusOpponentData* HexusOpponentDataInstance;
	static const std::string HexusSaveKey;
};
