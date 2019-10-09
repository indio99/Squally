#pragma once

#include "Engine/Quests/QuestTask.h"

class QuestLine;
class Sarude;
class Squally;

class BeatTutorialA : public QuestTask
{
public:
	static BeatTutorialA* create(GameObject* owner, QuestLine* questLine, std::string questTag);

	static const std::string MapKeyQuest;

protected:
	BeatTutorialA(GameObject* owner, QuestLine* questLine, std::string questTag);
	~BeatTutorialA();

	void onLoad(QuestState questState) override;
	void onActivate(bool isActiveThroughSkippable) override;
	void onComplete() override;
	void onSkipped() override;

private:
	typedef QuestTask super;

	void registerDialogue();

	Sarude* sarude;
	Squally* squally;
};
