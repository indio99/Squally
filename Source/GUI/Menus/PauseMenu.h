#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class PauseMenu : public Scene
{
public:
	PauseMenu();
	~PauseMenu();

	void onEnter() override;

private:
	void InitializeListeners();
	void OnKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void OnExitGame(Ref* pSender);
};
