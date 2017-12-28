#include "Mouse.h"

Mouse* Mouse::mouseInstance = nullptr;

Mouse* Mouse::claimInstance()
{
	Mouse* mouse = Mouse::getInstance();

	// Free the mouse from it's parent
	if (mouse->getParent() != nullptr)
	{
		mouse->getParent()->removeChild(Mouse::mouseInstance);
	}

	Mouse::mouseInstance->initializeListeners();

	return Mouse::mouseInstance;
}

Mouse* Mouse::getInstance()
{
	if (mouseInstance == nullptr)
	{
		Mouse::mouseInstance = new Mouse();
	}

	return Mouse::mouseInstance;
}

Mouse::Mouse()
{
	Director::getInstance();
	this->mouseSpriteIdle = Sprite::create(Resources::Menus_MouseIdle);
	this->mouseSpriteIdle->setAnchorPoint(Vec2(0.0f, 1.0f));
	this->mouseSpritePoint = Sprite::create(Resources::Menus_MousePoint);
	this->mouseSpritePoint->setAnchorPoint(Vec2(0.0f, 1.0f));

	this->mouseSpritePoint->setVisible(false);

	this->addChild(this->mouseSpriteIdle);
	this->addChild(this->mouseSpritePoint);
}

Mouse::~Mouse()
{
}

void Mouse::setCanClick(bool canClick)
{
	if (canClick)
	{
		this->mouseSpriteIdle->setVisible(false);
		this->mouseSpritePoint->setVisible(true);
	}
	else
	{
		this->mouseSpriteIdle->setVisible(true);
		this->mouseSpritePoint->setVisible(false);
	}
}

void Mouse::initializeListeners()
{
	EventListenerMouse* mouseListener = EventListenerMouse::create();

	mouseListener->onMouseMove = CC_CALLBACK_1(Mouse::onMouseMove, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

void Mouse::onMouseMove(EventMouse* event)
{
	this->mouseSpriteIdle->setPosition(Vec2(event->getCursorX(), event->getCursorY()));
	this->mouseSpritePoint->setPosition(Vec2(event->getCursorX(), event->getCursorY()));

	this->setCanClick(false);
	this->getEventDispatcher()->dispatchCustomEvent(this->MouseMoveEvent, &MouseEventArgs(event->getCursorX(), event->getCursorY(), event));
}