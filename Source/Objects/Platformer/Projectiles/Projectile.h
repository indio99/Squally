#pragma once

#include "Engine/Physics/CollisionObject.h"
#include "Engine/Hackables/HackableObject.h"

class PlatformerEntity;

class Projectile : public HackableObject
{
public:
	void whenCollidesWith(std::vector<CollisionType> collisionTypes, std::function<CollisionObject::CollisionResult(CollisionObject::CollisionData)> onCollision);
	void whenStopsCollidingWith(std::vector<CollisionType> collisionTypes, std::function<CollisionObject::CollisionResult(CollisionObject::CollisionData)> onCollisionEnd);
	void launchTowardsTarget(Node* target, cocos2d::Vec2 offset = cocos2d::Vec2::ZERO, float spinSpeed = 0.0f, cocos2d::Vec3 secondsPer256pxLinearDistance = cocos2d::Vec3(0.75f, 0.75f, 0.75f), cocos2d::Vec3 gravity = cocos2d::Vec3(0.0f, -768.0f, 0.0f));
	void setLaunchVelocity(cocos2d::Vec3 velocity);
	void setLaunchAcceleration(cocos2d::Vec3 acceleration);
	CollisionObject* getCollision();
	cocos2d::Vec3 getLaunchVelocity();
	cocos2d::Vec3 getLaunchAcceleration();
	void setSpeedMultiplier(cocos2d::Vec3 speedMultiplier);
	void enable(bool setVisible);
	void disable(bool setVisible);
	void reset();
	virtual void runSpawnFX();

	static const std::string ProjectileTag;
	
protected:
	Projectile(PlatformerEntity* caster, std::vector<cocos2d::Vec2>& hitBox, int collisionType, bool allowHacking);
	virtual	~Projectile();

	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	void update(float dt) override;
	void registerHackables() override;
	HackablePreview* createDefaultPreview() override;
	virtual HackablePreview* createVelocityPreview();
	virtual HackablePreview* createAccelerationPreview();
	
	PlatformerEntity* caster;

	cocos2d::Node* contentNode;
	cocos2d::Node* postFXNode;

private:
	typedef HackableObject super;

	CollisionObject* collisionObject;
	CollisionObject* ownerCollisionRef;
	float spinSpeed;
	bool allowHacking;
	cocos2d::Vec3 launchVelocity;
	cocos2d::Vec3 launchAcceleration;
	cocos2d::Vec3 speedMultiplier;
	float noOwnerCollideDuration;
};
