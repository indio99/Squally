#include "BossEvilEye.h"

BossEvilEye* BossEvilEye::create()
{
	BossEvilEye* instance = new BossEvilEye();

	instance->autorelease();

	return instance;
}

BossEvilEye::BossEvilEye() : Enemy::Enemy(
	Resources::Entities_Environment_Mech_BossEvilEye_Animations,
	false,
	Size(720.0f, 840.0f),
	0.6f,
	Vec2(0.0f, 0.0f))
{
}

BossEvilEye::~BossEvilEye()
{
}