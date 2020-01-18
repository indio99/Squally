#pragma once

#include "Objects/Platformer/Interactables/InteractObject.h"

namespace cocos2d
{
	class PhysicsBody;
	class Sprite;
}

class CollisionObject;
class SmartAnimationSequenceNode;
class WorldSound;

class Anvil : public InteractObject
{
public:
	static Anvil* create(cocos2d::ValueMap& properties);

	static const std::string MapKeyAnvil;

protected:
	Anvil(cocos2d::ValueMap& properties);
	virtual ~Anvil();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void onInteract() override;

private:
	typedef InteractObject super;

	cocos2d::Sprite* anvil;
	cocos2d::Node* floatContainer;
	cocos2d::Sprite* shine;
	cocos2d::Sprite* hammer;
};