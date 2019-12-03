#include "IceTerrain.h"

#include "cocos/base/CCValue.h"

#include "Resources/TerrainResources.h"
#include "Resources/TextureResources.h"

using namespace cocos2d;

const std::string IceTerrain::MapKeyTerrainType = "ice";

IceTerrain* IceTerrain::create(ValueMap& properties)
{
	IceTerrain* instance = new IceTerrain(properties);

	instance->autorelease();

	return instance;
}

IceTerrain::IceTerrain(ValueMap& properties) : super(
	properties,
	TerrainObject::TerrainData(
		0.5f,
		IceTerrain::MapKeyTerrainType,
		TextureResources::IceTexture,
		TerrainResources::Ice_Top,
		TerrainResources::Ice_TopLeft,
		TerrainResources::Ice_TopRight,
		TerrainResources::Ice_TopConnector,
		TerrainResources::BlueGrass_TopConnectorConcave,
		TerrainResources::BlueGrass_TopConnectorConcaveDeep,
		TerrainResources::BlueGrass_TopConnectorConvex,
		TerrainResources::BlueGrass_TopConnectorConvexDeep,
		TerrainResources::Ice_Bottom,
		TerrainResources::Ice_BottomLeft,
		TerrainResources::Ice_BottomRight,
		TerrainResources::Ice_BottomConnector,
		TerrainResources::Ice_Left,
		TerrainResources::Ice_LeftConnector,
		TerrainResources::Ice_Right,
		TerrainResources::Ice_RightConnector,
		// Top
		Vec2::ZERO,
		// Bottom
		Vec2::ZERO,
		// Left
		Vec2::ZERO,
		// Right
		Vec2::ZERO,
		// TopLeft
		Vec2::ZERO,
		// TopRight
		Vec2::ZERO,
		// BottomLeft
		Vec2::ZERO,
		// BottomRight
		Vec2::ZERO,
		// TopConnector
		Vec2::ZERO,
		// TopConnectorConcave
		Vec2::ZERO,
		// TopConnectorConcaveDeep
		Vec2::ZERO,
		// TopConnectorConvex
		Vec2::ZERO,
		// TopConnectorConvexDeep
		Vec2::ZERO,
		// BottomConnector
		Vec2::ZERO,
		// FillColor
		Color4B(11, 30, 39, 255)))
{
}

IceTerrain::~IceTerrain()
{
}
