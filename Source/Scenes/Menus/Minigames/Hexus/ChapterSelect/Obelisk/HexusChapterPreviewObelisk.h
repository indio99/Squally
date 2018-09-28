#pragma once
#include "cocos2d.h"
#include "Resources.h"

#include "Engine/UI/Controls/MenuSprite.h"
#include "Scenes/Menus/Minigames/Hexus/ChapterSelect/HexusChapterPreview.h"

using namespace cocos2d;

class HexusChapterPreviewObelisk : public HexusChapterPreview
{
public:
	static HexusChapterPreviewObelisk * create();

protected:
	HexusChapterPreviewObelisk();
	~HexusChapterPreviewObelisk();

private:
	void initializePositions() override;
};