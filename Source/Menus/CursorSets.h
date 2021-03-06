#pragma once

#include "Engine/UI/Mouse.h"

class CursorSets
{
public:
	enum CursorSet
	{
		Default = Mouse::SET_ID_DEFAULT,
		Globe = Mouse::SET_ID_TRANSLATION_CURSOR,
		PickPocket = 2,
	};

	static void registerCursorSets();
	static void setActiveCursorSet(CursorSet cursorSet);
};
