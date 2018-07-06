#include "IceGolem.h"

const std::string IceGolem::KeyEnemyIceGolem = "ice_golem";

IceGolem* IceGolem::deserialize(ValueMap* initProperties)
{
	IceGolem* instance = new IceGolem(initProperties);

	instance->autorelease();

	return instance;
}

IceGolem::IceGolem(ValueMap* initProperties) : Enemy(initProperties,
	Resources::Entities_Platformer_Environment_Snow_IceGolem_Animations,
	false,
	Size(1680.0f, 996.0f),
	0.35f,
	Vec2(0.0f, 0.0f))
{
}

IceGolem::~IceGolem()
{
}
