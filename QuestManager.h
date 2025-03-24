#ifndef QUESTMANAGER_H
#define QUESTMANAGER_H

#include <vector>
#include "Hero.h"
#include "GameWorld.h"

class Quest
{
    //Location* location;
    //std::vector<Character*> chars;
    Hero* hero;
    GameWorld* gameworld;
    public:
    //Quest(Location* loc):location(loc){};
    void create_hero();
    //void ad_character(Character* charac);
    void display_start();
    void display_current_stage();

};

class QuestManager 
{
private:
    std::vector<Quest*> activeQuests;
    std::vector<Quest*> completedQuests;

public:
    QuestManager();
    ~QuestManager();
    void assignQuest(Quest* quest);
    void checkCompletion();
    //void distributeRewards();
};

#endif