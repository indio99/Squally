#include "TalkToMages.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Dialogue/DialogueOption.h"
#include "Engine/Dialogue/SpeechBubble.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Events/QuestEvents.h"
#include "Engine/Save/SaveManager.h"
#include "Entities/Platformer/Helpers/EndianForest/Scrappy.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Sarude.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/NotificationEvents.h"
#include "Events/PlatformerEvents.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Dialogue/EntityDialogueBehavior.h"
#include "Scenes/Platformer/Dialogue/DialogueSet.h"
#include "Scenes/Platformer/Hackables/HackFlags.h"
#include "Scenes/Platformer/Quests/EndianForest/SaveTown/FightGorgon.h"
#include "Scenes/Platformer/Save/SaveKeys.h"

#include "Resources/ObjectResources.h"
#include "Resources/SoundResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string TalkToMages::MapKeyQuest = "talk-to-mages";

TalkToMages* TalkToMages::create(GameObject* owner, QuestLine* questLine)
{
	TalkToMages* instance = new TalkToMages(owner, questLine);

	instance->autorelease();

	return instance;
}

TalkToMages::TalkToMages(GameObject* owner, QuestLine* questLine) : super(owner, questLine, TalkToMages::MapKeyQuest, false)
{
	this->squally = nullptr;
	this->scrappy = nullptr;
	this->sarude = nullptr;
}

TalkToMages::~TalkToMages()
{
}

void TalkToMages::onLoad(QuestState questState)
{
	ObjectEvents::watchForObject<Squally>(this, [=](Squally* squally)
	{
		this->squally = squally;
	}, Squally::MapKey);
	
	ObjectEvents::watchForObject<Scrappy>(this, [=](Scrappy* scrappy)
	{
		this->scrappy = scrappy;
	}, Scrappy::MapKey);

	ObjectEvents::watchForObject<Sarude>(this, [=](Sarude* sarude)
	{
		this->sarude = sarude;
		this->setPostText();
	}, Sarude::MapKey);
}

void TalkToMages::onActivate(bool isActiveThroughSkippable)
{
	this->listenForMapEventOnce(TalkToMages::MapKeyQuest, [=](ValueMap args)
	{
		this->runCinematicSequencePart1();
	});
}

void TalkToMages::onComplete()
{
	this->setPostText();
}

void TalkToMages::onSkipped()
{
}

void TalkToMages::runCinematicSequencePart1()
{
	DialogueEvents::TriggerOpenDialogue(DialogueEvents::DialogueOpenArgs(
		Strings::Platformer_Quests_EndianForest_SaveTown_Sarude_A_YouMadeIt::create(),
		DialogueEvents::DialogueVisualArgs(
			DialogueBox::DialogueDock::Bottom,
			DialogueBox::DialogueAlignment::Right,
			DialogueEvents::BuildPreviewNode(&this->squally, false),
			DialogueEvents::BuildPreviewNode(&this->sarude, true)
		),
		[=]()
		{
			this->runCinematicSequencePart2();
		},
		SoundResources::Platformer_Entities_Generic_ChatterMedium3,
		false
	));
}

void TalkToMages::runCinematicSequencePart2()
{
	DialogueEvents::TriggerOpenDialogue(DialogueEvents::DialogueOpenArgs(
		Strings::Platformer_Quests_EndianForest_SaveTown_Sarude_B_WhatsThePlan::create(),
		DialogueEvents::DialogueVisualArgs(
			DialogueBox::DialogueDock::Bottom,
			DialogueBox::DialogueAlignment::Left,
			DialogueEvents::BuildPreviewNode(&this->scrappy, false),
			DialogueEvents::BuildPreviewNode(&this->sarude, true)
		),
		[=]()
		{
			this->runCinematicSequencePart3();
		},
		SoundResources::Platformer_Entities_Droid_DroidBrief2,
		false
	));
}

void TalkToMages::runCinematicSequencePart3()
{
	DialogueEvents::TriggerOpenDialogue(DialogueEvents::DialogueOpenArgs(
		Strings::Platformer_Quests_EndianForest_SaveTown_Sarude_C_Infiltrate::create(),
		DialogueEvents::DialogueVisualArgs(
			DialogueBox::DialogueDock::Bottom,
			DialogueBox::DialogueAlignment::Right,
			DialogueEvents::BuildPreviewNode(&this->squally, false),
			DialogueEvents::BuildPreviewNode(&this->sarude, true)
		),
		[=]()
		{
			this->runCinematicSequencePart4();
		},
		SoundResources::Platformer_Entities_Generic_ChatterMedium4,
		false
	));
}

void TalkToMages::runCinematicSequencePart4()
{
	DialogueEvents::TriggerOpenDialogue(DialogueEvents::DialogueOpenArgs(
		Strings::Platformer_Quests_EndianForest_SaveTown_Sarude_D_GoNow::create(),
		DialogueEvents::DialogueVisualArgs(
			DialogueBox::DialogueDock::Bottom,
			DialogueBox::DialogueAlignment::Right,
			DialogueEvents::BuildPreviewNode(&this->squally, false),
			DialogueEvents::BuildPreviewNode(&this->sarude, true)
		),
		[=]()
		{
			this->complete();
		},
		SoundResources::Platformer_Entities_Generic_ChatterMedium1,
		true
	));
}

void TalkToMages::setPostText()
{
	if (this->sarude == nullptr)
	{
		return;
	}

	if (QuestTask::getQuestStateForTask(this->questLine, FightGorgon::MapKeyQuest) == QuestState::Complete)
	{
		return;
	}
	
	this->defer([=]()
	{
		this->sarude->watchForAttachedBehavior<EntityDialogueBehavior>([=](EntityDialogueBehavior* interactionBehavior)
		{
			interactionBehavior->enqueuePretext(DialogueEvents::DialogueOpenArgs(
				Strings::Platformer_Quests_EndianForest_SaveTown_Sarude_D_GoNow::create(),
				DialogueEvents::DialogueVisualArgs(
					DialogueBox::DialogueDock::Bottom,
					DialogueBox::DialogueAlignment::Right,
					DialogueEvents::BuildPreviewNode(&this->squally, false),
					DialogueEvents::BuildPreviewNode(&this->sarude, true)
				),
				[=]()
				{
					this->setPostText();
				},
				SoundResources::Platformer_Entities_Generic_ChatterMedium1,
				true
			));
		});
	});
}
