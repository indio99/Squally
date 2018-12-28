#include "HackableObject.h"

#include "base/CCEventListenerCustom.h"

#include "Engine/Hackables/HackableData.h"
#include "Engine/Hackables/HackButton.h"
#include "Engine/UI/Controls/MenuSprite.h"
#include "Engine/Events/HackableEvents.h"

#include "Resources/UIResources.h"
#include "Engine/Utils/GameUtils.h"

using namespace cocos2d;

HackableObject::HackableObject(ValueMap* initProperties) : SerializableObject(initProperties)
{
	this->dataList = std::vector<HackableData*>();
	this->hackButton = HackButton::create();
	
	this->hackButton->setVisible(false);

	this->addChild(this->hackButton);
}

HackableObject::~HackableObject()
{
}

void HackableObject::onEnterTransitionDidFinish()
{
	Node::onEnterTransitionDidFinish();

	this->hackButton->setClickCallback(CC_CALLBACK_1(HackableObject::onHackableClick, this));

	HackableEvents::TriggerRegisterHackable(HackableEvents::HackableObjectRegisterArgs(this));
}

void HackableObject::initializeListeners()
{
	SerializableObject::initializeListeners();

	this->addEventListenerIgnorePause(EventListenerCustom::create(HackableEvents::HackerModeEnable, [=](EventCustom* args)
	{
		this->onHackerModeEnable();
	}));

	this->addEventListenerIgnorePause(EventListenerCustom::create(HackableEvents::HackerModeDisable, [=](EventCustom* args)
	{
		this->onHackerModeDisable();
	}));
}

void HackableObject::onHackerModeEnable()
{
	if (!this->dataList.empty())
	{
		this->hackButton->setVisible(true);
	}
}

void HackableObject::onHackerModeDisable()
{
	this->hackButton->setVisible(false);
}

Vec2 HackableObject::getButtonOffset()
{
	return Vec2::ZERO;
}

void HackableObject::onHackableClick(MenuSprite* hackButton)
{
	Vec2 screenPosition = this->getParent()->convertToWorldSpace(this->getPosition()) + this->getButtonOffset();
	Vec2 newPosition = GameUtils::getSceneBounds(this).origin;

	HackableEvents::TriggerEditHackable(HackableEvents::HackableObjectEditArgs(this, newPosition));
}

void HackableObject::registerData(HackableData* hackableData)
{
	hackableData->retain();
	this->dataList.push_back(hackableData);
}
