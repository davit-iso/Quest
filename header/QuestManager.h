#ifndef QUESTMANAGER_H
#define QUESTMANAGER_H

// #include <vector>
// #include "Hero.h"
// #include "GameWorld.h"
#include "header.hpp"

class Hero;
class GameWorld;
class Monster;

class Quest
{
    //Location* location;
    //std::vector<Character*> chars;
    Hero* hero;
    GameWorld* gameworld;
    bool lost = false;
    public:
    //Quest(Location* loc):location(loc){};
    void create_hero();
    void create_GameWorld();
    GameWorld* get_GameWorld();
    //void ad_character(Character* charac);
    void display_current_stage();
    void fight(Hero*,Monster*);
    Monster* get_mons_by_name(std::string _name);
    void show_menu(Hero*, Monster*);
    //void show_main_menu();
    bool get_lost();
    void set_lost();
    bool sumbit_win_q();
    Hero* get_hero();
    void set_hero(Hero*);
    virtual ~Quest();
};

class QuestManager 
{
private:
    bool win_game = false;
    std::vector<Quest*> activeQuests;
    std::vector<Quest*> completedQuests;

public:
    QuestManager() = default;
    ~QuestManager();
    void show_main_menu() const;
    bool _win();
    //void assignQuest(Quest* quest);
    void checkCompletion();
    void change_hero();
    void createQuest();
    void start_game();
    //void distributeRewards();
};

#endif