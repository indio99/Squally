#include "Thurstan.h"

const std::string Thurstan::MapKeyNpcThurstan = "thurstan";

Thurstan* Thurstan::deserialize(ValueMap* initProperties)
{
	Thurstan* instance = new Thurstan(initProperties);

	instance->autorelease();

	return instance;
}

Thurstan::Thurstan(ValueMap* initProperties) : NpcBase(initProperties,
	Resources::Entities_Platformer_Environment_Castle_Npcs_Thurstan_Animations,
	PlatformerCollisionMapping::KeyCollisionTypeEnemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Thurstan::~Thurstan()
{
}