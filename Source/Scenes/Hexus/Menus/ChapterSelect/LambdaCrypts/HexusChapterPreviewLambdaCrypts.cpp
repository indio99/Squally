#include "HexusChapterPreviewLambdaCrypts.h"

#include "cocos/2d/CCClippingNode.h"
#include "cocos/2d/CCSprite.h"

#include "Engine/Localization/LocalizedLabel.h"

#include "Resources/UIResources.h"

#include "Strings/Menus/Maps/LambdaCrypts.h"

using namespace cocos2d;

const std::string HexusChapterPreviewLambdaCrypts::SaveKeyChapterName = "HEXUS_CHAPTER_JUNGLE";

HexusChapterPreviewLambdaCrypts* HexusChapterPreviewLambdaCrypts::create()
{
	HexusChapterPreviewLambdaCrypts* instance = new HexusChapterPreviewLambdaCrypts();

	instance->autorelease();

	return instance;
}

HexusChapterPreviewLambdaCrypts::HexusChapterPreviewLambdaCrypts() : HexusChapterPreview(HexusChapterPreviewLambdaCrypts::SaveKeyChapterName, Strings::Menus_Maps_LambdaCrypts::create())
{
	this->frameClip->addChild(Sprite::create(UIResources::Menus_Hexus_HexusFrameLambdaCrypts));
}

HexusChapterPreviewLambdaCrypts::~HexusChapterPreviewLambdaCrypts()
{
}

void HexusChapterPreviewLambdaCrypts::initializePositions()
{
	super::initializePositions();
}