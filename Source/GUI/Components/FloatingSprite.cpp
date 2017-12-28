#include "FloatingSprite.h"

FloatingSprite* FloatingSprite::create(std::string spriteResourcePath, Vec2 movement, Vec2 time)
{
	FloatingSprite* floatingSprite = new FloatingSprite(spriteResourcePath, movement, time);

	floatingSprite->autorelease();

	return floatingSprite;
}

FloatingSprite::FloatingSprite(std::string spriteResourcePath, Vec2 movement, Vec2 time)
{
	this->sprite = Sprite::create(spriteResourcePath);
	this->addChild(this->sprite);

	FiniteTimeAction* bounceX1 = EaseSineInOut::create(MoveBy::create(time.x, Vec2(movement.x, 0.0f)));
	FiniteTimeAction* bounceX2 = EaseSineInOut::create(MoveBy::create(time.x, Vec2(-movement.x, 0.0f)));
	FiniteTimeAction* bounceY1 = EaseSineInOut::create(MoveBy::create(time.y, Vec2(0.0f, movement.y)));
	FiniteTimeAction* bounceY2 = EaseSineInOut::create(MoveBy::create(time.y, Vec2(0.0f, -movement.y)));

	this->runAction(RepeatForever::create(Sequence::create(bounceX1, bounceX2, nullptr)));
	this->runAction(RepeatForever::create(Sequence::create(bounceY1, bounceY2, nullptr)));

	this->scheduleUpdate();
}

void FloatingSprite::setFlippedX(bool flipped)
{
	this->sprite->setFlippedX(flipped);
}

void FloatingSprite::setFlippedY(bool flipped)
{
	this->sprite->setFlippedX(flipped);
}

FloatingSprite::~FloatingSprite()
{
}