#include "StateDrawInitial.h"

StateDrawInitial* StateDrawInitial::create()
{
	StateDrawInitial* instance = new StateDrawInitial();

	instance->autorelease();

	return instance;
}

StateDrawInitial::StateDrawInitial() : StateBase(GameState::StateType::DrawInitialCards)
{
}

StateDrawInitial::~StateDrawInitial()
{
}

void StateDrawInitial::onBeforeStateEnter(GameState* gameState)
{
	StateBase::onBeforeStateEnter(gameState);
}

void StateDrawInitial::onStateEnter(GameState* gameState)
{
	StateBase::onStateEnter(gameState);

	const float indexDelay = 0.1f;

	// Draw starting cards
	std::vector<Card*> drawnCards = std::vector<Card*>();

	for (int index = 0; index < Config::startingCardAmount; index++)
	{
		if (gameState->playerDeck->hasCards())
		{
			Card* card = gameState->playerDeck->drawCard();

			GameUtils::changeParent(card, this, true);

			drawnCards.push_back(card);
		}
	}

	this->runAction(Sequence::create(
		CallFunc::create(CC_CALLBACK_0(CardRow::insertCards, gameState->playerHand, drawnCards, Config::insertDelay, indexDelay)),
		nullptr
	));

	for (int index = 0; index < Config::startingCardAmount; index++)
	{
		if (gameState->enemyDeck->hasCards())
		{
			gameState->enemyHand->insertCard(gameState->enemyDeck->drawCard(), 0.0f);
		}
	}

	this->runAction(Sequence::create(
		DelayTime::create(0.5f),
		CallFunc::create([=]()
		{
			GameState::updateState(gameState, GameState::StateType::RoundStart);
		}),
		nullptr
	));
}

void StateDrawInitial::onStateReload(GameState* gameState)
{
	StateBase::onStateReload(gameState);
}

void StateDrawInitial::onStateExit(GameState* gameState)
{
	StateBase::onStateExit(gameState);
}