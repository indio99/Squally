#pragma once
#include "cocos2d.h"

#include "Engine/Maps/IObjectDeserializer.h"
#include "Entities/Platformer/Npcs/Mech/MechNpcs.h"
#include "Entities/Platformer/PlatformerEntityDeserializer.h"

using namespace cocos2d;

class MechNpcDeserializer : public PlatformerEntityDeserializer
{
public:
	MechNpcDeserializer();
	~MechNpcDeserializer();

	void onDeserializationRequest(ObjectDeserializationRequestArgs* args) override;
};