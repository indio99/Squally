#include "MechDog.h"

MechDog* MechDog::create()
{
	MechDog* instance = new MechDog();

	instance->autorelease();

	return instance;
}

MechDog::MechDog() : Enemy::Enemy(
	Resources::Entities_Environment_Volcano_BossDemonKing_Animations,
	false)
{
}

MechDog::~MechDog()
{
}