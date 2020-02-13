#pragma once

#include "Scenes/Platformer/AttachedBehavior/Entities/Friendly/Hexus/HexusBehaviorBase.h"

class CardData;
class HexusOpponentData;
class MinMaxPool;
class PlatformerEntity;

class BlackbeardHexusBehavior : public HexusBehaviorBase
{
public:
	static BlackbeardHexusBehavior* create(GameObject* owner);

	static const std::string MapKeyAttachedBehavior;

protected:
	BlackbeardHexusBehavior(GameObject* owner);
	virtual ~BlackbeardHexusBehavior();

	MinMaxPool* generateReward() override;
	std::string getWinLossSaveKey() override;
	std::string getBackgroundResource() override;
	std::vector<CardData*> generateDeck() override;
	StateOverride* getStateOverride() override;
	std::vector<TutorialBase*> getTutorials() override;

private:
	typedef HexusBehaviorBase super;

};