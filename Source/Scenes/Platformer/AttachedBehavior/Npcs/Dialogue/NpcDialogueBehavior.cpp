#include "NpcDialogueBehavior.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/DialogueSet.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Localization/ConstantString.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Physics/EngineCollisionTypes.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Entities/Platformer/Squally/Squally.h"
#include "Events/DialogueEvents.h"
#include "Menus/Interact/InteractMenu.h"
#include "Scenes/Platformer/Level/Physics/PlatformerCollisionType.h"
#include "Scenes/Platformer/State/StateKeys.h"

#include "Resources/EntityResources.h"

#include "Strings/Common/Brackets.h"
#include "Strings/Common/Dash.h"
#include "Strings/Common/Empty.h"
#include "Strings/Common/Newline.h"
#include "Strings/Common/Triconcat.h"
#include "Strings/Platformer/Entities/Goodbye.h"

using namespace cocos2d;

const std::string NpcDialogueBehavior::MapKeyAttachedBehavior = "npc-interaction";

NpcDialogueBehavior* NpcDialogueBehavior::create(GameObject* owner)
{
	NpcDialogueBehavior* instance = new NpcDialogueBehavior(owner);

	instance->autorelease();

	return instance;
}

NpcDialogueBehavior::NpcDialogueBehavior(GameObject* owner) : super(owner)
{
	this->entity = dynamic_cast<PlatformerEntity*>(owner);
	this->squally = nullptr;
	this->interactMenu = InteractMenu::create(ConstantString::create("[V]"));
	this->canInteract = false;
	this->dialogueCollision = nullptr;
	this->dialogueSetNode = Node::create();
	this->mainDialogueSet = DialogueSet::create();
	this->activeDialogueSet = this->mainDialogueSet;

	this->addDialogueSet(this->mainDialogueSet);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}
	else
	{
		this->dialogueCollision = CollisionObject::create(
			PhysicsBody::createBox(this->entity->getEntitySize()),
			(CollisionType)PlatformerCollisionType::Trigger,
			false,
			false
		);

		this->interactMenu->setPosition(this->entity->getCollisionOffset() + Vec2(0.0f, this->entity->getMovementSize().height / 2.0f));

		Vec2 collisionOffset = this->entity->getCollisionOffset();

		if (this->entity->isFlippedY())
		{
			Vec2 offset = Vec2(collisionOffset.x, -collisionOffset.y) - Vec2(0.0f, this->entity->getEntitySize().height / 2.0f);
			this->dialogueCollision->inverseGravity();
			this->dialogueCollision->getPhysicsBody()->setPositionOffset(offset);
		}
		else
		{
			Vec2 offset = collisionOffset + Vec2(0.0f, this->entity->getEntitySize().height / 2.0f);
			this->dialogueCollision->getPhysicsBody()->setPositionOffset(offset);
		}

		this->addChild(this->dialogueCollision);
	}
	
	this->addChild(this->interactMenu);
}

NpcDialogueBehavior::~NpcDialogueBehavior()
{
}

void NpcDialogueBehavior::onLoad()
{
	ObjectEvents::watchForObject<Squally>(this, [=](Squally* squally)
	{
		this->squally = squally;
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_V }, [=](InputEvents::InputArgs* args)
	{
		if (this->canInteract)
		{
			this->setActiveDialogueSet(this->getMainDialogueSet());
		}
	});

	this->dialogueCollision->whenCollidesWith({ (int)PlatformerCollisionType::Player }, [=](CollisionObject::CollisionData data)
	{
		this->canInteract = true;
		this->interactMenu->show();

		return CollisionObject::CollisionResult::DoNothing;
	});
		 
	this->dialogueCollision->whenStopsCollidingWith({ (int)PlatformerCollisionType::Player }, [=](CollisionObject::CollisionData data)
	{
		this->canInteract = false;
		this->interactMenu->hide();

		return CollisionObject::CollisionResult::DoNothing;
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_1 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(1);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_2 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(2);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_3 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(3);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_4 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(4);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_5 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(5);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_6 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(6);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_7 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(7);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_8 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(8);
	});

	this->whenKeyPressed({ EventKeyboard::KeyCode::KEY_9 }, [=](InputEvents::InputArgs* args)
	{
		this->chooseOption(9);
	});

	this->mainDialogueSet->addDialogueOption(DialogueSet::DialogueOption(Strings::Platformer_Entities_Goodbye::create(), nullptr), 0.01f);
	this->addChild(this->dialogueSetNode);
}

void NpcDialogueBehavior::setActiveDialogueSet(DialogueSet* dialogueSet, bool showDialogue)
{
	this->activeDialogueSet = dialogueSet;

	if (showDialogue)
	{
		this->showOptions();
	}
}

void NpcDialogueBehavior::addDialogueSet(DialogueSet* dialogueSet)
{
	this->dialogueSets.push_back(dialogueSet);
	this->dialogueSetNode->addChild(dialogueSet);
}

void NpcDialogueBehavior::removeDialogueSet(DialogueSet* dialogueSet)
{
	this->dialogueSets.erase(std::find(this->dialogueSets.begin(), this->dialogueSets.end(), dialogueSet));
	this->dialogueSetNode->removeChild(dialogueSet);
}

DialogueSet* NpcDialogueBehavior::getMainDialogueSet()
{
	return this->mainDialogueSet;
}

void NpcDialogueBehavior::chooseOption(int option)
{
	if (--option < 0 || option >= this->activeDialogueSet->dialogueOptions.size())
	{
		return;
	}

	DialogueEvents::TriggerDialogueClose();

	if (std::get<0>(this->activeDialogueSet->dialogueOptions[option]).onDialogueChosen != nullptr)
	{
		std::get<0>(this->activeDialogueSet->dialogueOptions[option]).onDialogueChosen();
	}
}

void NpcDialogueBehavior::showOptions()
{
	if (this->activeDialogueSet->dialogueOptions.empty() || (this->squally != nullptr && this->squally->getStateOrDefaultBool(StateKeys::CinematicHijacked, false)))
	{
		return;
	}

	std::sort(this->activeDialogueSet->dialogueOptions.begin(), this->activeDialogueSet->dialogueOptions.end(), 
		[](const std::tuple<DialogueSet::DialogueOption, float>& a, const std::tuple<DialogueSet::DialogueOption, float>& b)
	{ 
		return std::get<1>(a) > std::get<1>(b); 
	});

	LocalizedString* options = Strings::Common_Triconcat::create();
	LocalizedString* nextOption = options;
	LocalizedString* currentOption = nextOption;
	int index = 1;

	for (auto it = this->activeDialogueSet->dialogueOptions.begin(); it != this->activeDialogueSet->dialogueOptions.end(); it++, index++)
	{
		bool lastIter = it == (--this->activeDialogueSet->dialogueOptions.end());

		LocalizedString* newline = Strings::Common_Newline::create();
		nextOption = lastIter ? (LocalizedString*)Strings::Common_Empty::create() : (LocalizedString*)Strings::Common_Triconcat::create();
		LocalizedString* option = this->getOptionString(index, std::get<0>((*it)).dialogueOption->clone());

		currentOption->setStringReplacementVariables({option , newline, nextOption });
		currentOption = nextOption;
	}

	DialogueEvents::TriggerDialogueOpen(DialogueEvents::DialogueOpenArgs(
		options,
		DialogueBox::DialogueDock::Bottom,
		DialogueBox::DialogueAlignment::Left,
		[=]()
		{
		},
		DialogueEvents::BuildPreviewNode(this->entity, false),
		DialogueEvents::BuildPreviewNode(this->squally, true)
	));
}

LocalizedString* NpcDialogueBehavior::getOptionString(int index, LocalizedString* optionText)
{
	LocalizedString* dash = Strings::Common_Dash::create();
	LocalizedString* brackets = Strings::Common_Brackets::create();

	brackets->setStringReplacementVariables(ConstantString::create(std::to_string(index)));

	dash->setStringReplacementVariables({ brackets, optionText });

	return dash;
}