#include "CipherState.h"

#include "cocos/base/CCDirector.h"
#include "cocos/base/CCEventDispatcher.h"

#include "Engine/Utils/StrUtils.h"

#include "Resources/EntityResources.h"
#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string CipherState::requestStateUpdateEvent = "EVENT_CIPHER_REQUEST_UPDATE_STATE";
const std::string CipherState::beforeStateUpdateEvent = "EVENT_CIPHER_BEFORE_UPDATE_STATE";
const std::string CipherState::onStateUpdateEvent = "EVENT_CIPHER_ON_UPDATE_STATE";

CipherState* CipherState::create()
{
	CipherState* instance = new CipherState();

	instance->autorelease();

	return instance;
}

CipherState::CipherState()
	: stateType(StateType::EmptyState),
	updateStateCallback(nullptr)
{
}

CipherState::~CipherState()
{
}

void CipherState::initializePositions()
{
	SmartNode::initializePositions();

	Size visibleSize = Director::getInstance()->getVisibleSize();
}

void CipherState::updateState(CipherState* gameState, StateType newState)
{
	gameState->previousStateType = gameState->stateType;
	gameState->stateType = newState;
	gameState->clearInteraction();

	switch (newState)
	{
		case StateType::GameStart:
		{
			gameState->gameStartTime = std::chrono::high_resolution_clock::now();
			break;
		}
		case StateType::GameEnd:
		{
			gameState->gameEndTime = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double> elapsed = gameState->gameEndTime - gameState->gameStartTime;
			gameState->gameDurationInSeconds = (int)(elapsed.count());
			break;
		}
		default:
		{
			break;
		}
	}

	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(CipherState::requestStateUpdateEvent, gameState);
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(CipherState::beforeStateUpdateEvent, gameState);
	Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(CipherState::onStateUpdateEvent, gameState);
}

void CipherState::clearInteraction()
{
}