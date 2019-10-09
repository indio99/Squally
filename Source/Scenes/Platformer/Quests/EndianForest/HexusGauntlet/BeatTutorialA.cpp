#include "BeatTutorialA.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/SpeechBubble.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Events/QuestEvents.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Sarude.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/DialogueEvents.h"
#include "Events/PlatformerEvents.h"

using namespace cocos2d;

const std::string BeatTutorialA::MapKeyQuest = "beat-tutorial-A";

BeatTutorialA* BeatTutorialA::create(GameObject* owner, QuestLine* questLine,  std::string questTag)
{
	BeatTutorialA* instance = new BeatTutorialA(owner, questLine, questTag);

	instance->autorelease();

	return instance;
}

BeatTutorialA::BeatTutorialA(GameObject* owner, QuestLine* questLine, std::string questTag) : super(owner, questLine, BeatTutorialA::MapKeyQuest, questTag, false)
{
	this->sarude = nullptr;
	this->squally = nullptr;
}

BeatTutorialA::~BeatTutorialA()
{
}

void BeatTutorialA::onLoad(QuestState questState)
{
	ObjectEvents::watchForObject<Sarude>(this, [=](Sarude* sarude)
	{
		this->sarude = sarude;
	});

	ObjectEvents::watchForObject<Squally>(this, [=](Squally* squally)
	{
		this->squally = squally;
	});
}

void BeatTutorialA::onActivate(bool isActiveThroughSkippable)
{
}

void BeatTutorialA::onComplete()
{
}

void BeatTutorialA::onSkipped()
{
	this->removeAllListeners();
}

void BeatTutorialA::registerDialogue()
{
	PlatformerEvents::TriggerCinematicHijack();

	this->runAction(Sequence::create(
		DelayTime::create(3.0f),
		CallFunc::create([=]()
		{
			DialogueEvents::TriggerDialogueOpen(DialogueEvents::DialogueOpenArgs(
				nullptr,
				DialogueBox::DialogueDock::Top,
				DialogueBox::DialogueAlignment::Left,
				[=]()
				{
				},
				DialogueEvents::BuildPreviewNode(this->sarude, false),
				DialogueEvents::BuildPreviewNode(this->squally, true),
				false
			));
		}),
		nullptr
	));
}