#pragma once
#include "cocos2d.h"
#include "Resources.h"

using namespace cocos2d;

class InputManager : public Node
{
public:
	static InputManager * claimInstance();
	static InputManager * getInstance();

	bool isKeyJustPressed(EventKeyboard::KeyCode keyCode);
	bool isPressed(EventKeyboard::KeyCode keyCode);
	bool isReleased(EventKeyboard::KeyCode keyCode);

private:
	InputManager();
	~InputManager();

	void InitializeListeners();

	void update(float dt) override;
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);

	std::unordered_map<EventKeyboard::KeyCode, bool>* pressedKeysPrevious;
	std::unordered_map<EventKeyboard::KeyCode, bool>* pressedKeys;

	static InputManager * inputManagerInstance;
};