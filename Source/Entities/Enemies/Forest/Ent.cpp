#include "Ent.h"

const std::string Ent::KeyEnemyEnt = "ent";

Ent* Ent::deserialize(ValueMap* initProperties)
{
	Ent* instance = new Ent(initProperties);

	instance->autorelease();

	return instance;
}

Ent::Ent(ValueMap* initProperties) : Enemy(initProperties,
	Resources::Entities_Platformer_Environment_Forest_Ent_Animations,
	false,
	Size(512.0f, 960.0f),
	0.3f,
	Vec2(24.0f, -452.0f))
{
}

Ent::~Ent()
{
}
