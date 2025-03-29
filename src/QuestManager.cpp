// #include "QuestManager.h"
// #include <iostream>
// #include "Hero.h"
#include "header.hpp"

void Quest::create_hero()
{
    //Hero* hero = nullptr;
    int tmp = -1;
    std::cout<<"What kind of HERO do you want to create??"<<std::endl;
    std::cout<<"Choose\nWarior - 1\nMage - 2\nRogue - 3"<<std::endl;
    std::cin>>tmp;
    while(true)
    {
        if(tmp == 1)
        {
            std::string ts;
            std::cout<<"Choose name for warrior"<<std::endl;
            std::cin>>ts;
            hero = new Warrior(ts);
            std::cout<<"The Warrior - "<<ts<<" was created successfully!"<<std::endl;
            break;
        }
        else if(tmp == 2)
        {
            std::string ts;
            std::cout<<"Choose name for mage"<<std::endl;
            std::cin>>ts;
            hero = new Mage(ts);
            std::cout<<"The Mage - "<<ts<<" was created successfully!"<<std::endl;
            break;
        }
        else if(tmp == 3)
        {
            std::string ts;
            std::cout<<"Choose name for rogue"<<std::endl;
            std::cin>>ts;
            hero = new Rogue(ts);
            std::cout<<"The Rogue - "<<" was created successfully!"<<std::endl;
            break;
        }
        std::cout<<"Try again\nWarior - 1\nMage - 2\nRogue - 3"<<std::endl;
        std::cin>>tmp;
    }
}

void Quest::display_current_stage()
{
    gameworld -> display_alive_monsters();
}

Monster* Quest::get_mons_by_name(std::string _name)
{
    return gameworld ->get_monster(_name);
}

GameWorld* Quest::get_GameWorld()
{
    return gameworld;
}

void QuestManager::show_main_menu() const
{
    std::cout<<"1 - The state of the hero\n";
    //hero -> displayStats();
    std::cout<<"2 - Display all characters of Quest\n";
    //gameworld -> display_characters();
    std::cout<<"3 - Display alive Monsters\n";
    //gameworld -> display_alive_monsters();
    std::cout<<"4 - Fight with monster\n";
    //
    std::cout<<"5 - Submit win\n";
    std::cout<<"6 - Dialog with NPC\n";
    std::cout<<"7 - Exit the game\n";
}

void Quest::show_menu(Hero* hero, Monster* monster)
{
    std::cout<<"Choose what you want to do\n1 - ATTACK\n2 - USE ABILITY\n3 - RETREAT\nState of the MONSTER\n";
    monster -> displayStats();
    std::cout<<"State of the HERO";
    hero -> displayStats();
}

void Quest::fight(Hero* hero, Monster* monster)
{
    if(monster -> get_health() <= 0)
    {
        std::cout<<"You already killed him!!"<<std::endl;
        return;
    }
    int _xp = monster -> get_health();  // xp for current fight 
    while(true)
    {
        int tmp = 0;
        show_menu(hero,monster);
        std::cin>>tmp;
        if(tmp == 3)
        {
            set_lost();
            std::cout<<"Game over!!"<<std::endl;
            return;
        }
        else if(tmp == 1)        // hero
        {
            hero -> attack(monster);
        }
        else if(tmp == 2)
        {
            if(hero -> get_ab_counter() >= 3)
            {
                hero -> useAbility(monster);
            }
            else
            {
                std::cout<<"You missed!!"<<std::endl;
            }
        }
        else
        {
            std::cout<<"You missed!!"<<std::endl;
        }

        monster -> set_ab_counter(monster -> get_ab_counter_m() + 1);

        if(monster -> get_health() <= 0)
        {
            hero -> add_xp(_xp);
            hero -> add_health(_xp / 2);
            
            std::cout<<"You killed him!!!\nAdded XP - "<<_xp<<"\nAdded health - "<<(_xp / 2)<<"\nAdded defense - 5"<<std::endl;
            hero -> displayStats();
            return;
        }

        if(monster -> get_ab_counter_m() >= 4)
        {
            monster -> useAbility(hero);
            monster -> set_ab_counter(0);   // 4 um avtomat useAbility
        }
        else
        {
            monster -> attack(hero);
        }
        if(hero -> get_health() <= 0)
        {
            std::cout<<"Game over!!!\nMerav heros@"<<std::endl;
            set_lost();
            return;
        }
        hero -> inc_ab_counter();
    }
}

void QuestManager::start_game()
{
    this -> createQuest();
    this -> activeQuests[0] -> create_hero();
    this -> createQuest();
    int tmp_menu = -1;
    while(true)
    {
        show_main_menu();
        std::cin>>tmp_menu;
        if(tmp_menu == 7)
        {
            std::cout<<"The game was interrupted!"<<std::endl;
            return;
        }
        else if(tmp_menu == 1)
        {
            this -> activeQuests[0] -> get_hero() -> displayStats();
        }
        else if(tmp_menu == 2)
        {
            this -> activeQuests[0] -> get_GameWorld() -> display_characters();
        }
        else if(tmp_menu == 3)
        {
            this -> activeQuests[0] -> display_current_stage();
        }
        else if(tmp_menu == 4)
        {
            std::string nm;
            std::cout<<"Input Monster name"<<std::endl;
            std::cin>>nm;
            this -> activeQuests[0] -> fight(this -> activeQuests[0] ->get_hero(),(this -> activeQuests[0] -> get_mons_by_name(nm)));
            if(activeQuests[0] -> get_lost())
            {
                std::cout<<"You lose!!"<<std::endl;
                return;
            }
        }
        else if(tmp_menu == 5)
        {
            checkCompletion();
            if(win_game == true)
            {
                return;
            }
        }
        else if(tmp_menu == 6)
        {
            std::string nmn;
            std::cout<<"Input NPC name\n";
            std::cin>>nmn;
            if(activeQuests[0] -> get_GameWorld() -> get_npc(nmn))
            {
                std::cout<<activeQuests[0] -> get_hero() -> getDialogue();
                std::cout<<activeQuests[0] -> get_GameWorld() -> get_npc(nmn) -> getDialogue();
            }
        }
        else
        {
            std::cout<<"Try again!"<<std::endl;
        }
    }
}

bool Quest::get_lost()
{
    return lost;
}

void Quest::set_lost()
{
    lost = true;
}

bool Quest::sumbit_win_q()
{
    if(gameworld -> alive_mons_count() == 0)
    {
        return true;
    }
    return false;
}

void QuestManager::checkCompletion()
{
    std::cout<<"Check"<<std::endl;
    if(activeQuests[0] -> get_GameWorld() -> alive_mons_count() == 0)
    {
        std::cout<<"You win quest!!!"<<std::endl;
        completedQuests.push_back(activeQuests[0]);
        activeQuests.erase(activeQuests.begin());
        if(activeQuests.size() == 0)
        {
            std::cout<<"You win the game!!!!!"<<std::endl;
            win_game = true;
        }
        else
        {
            std::cout<<"Quest changed!"<<std::endl;
            change_hero();
        }
    }
    else
    {
        std::cout<<"There are still monsters alive."<<std::endl;
    }
}

bool QuestManager::_win()
{
    return win_game;
}

Hero* Quest::get_hero()
{
    return hero;
}

void Quest::set_hero(Hero* h)
{
    hero = h;
}

void QuestManager::change_hero()
{
    activeQuests[0] -> set_hero(completedQuests[0] -> get_hero());
}

Quest::~Quest()
{
    delete gameworld;
}

QuestManager::~QuestManager()
{
    delete completedQuests[0] ->get_hero();
    for(auto q : completedQuests)
    {
        delete q;
    }
    for(auto q : activeQuests)
    {
        delete q;
    }
}

void Quest::create_GameWorld()
{
    std::cout<<"Creating GameWorld"<<std::endl;
    gameworld = new GameWorld();
    gameworld -> create_loc();
    gameworld -> create_monster();
    gameworld -> create_monster();
    gameworld -> create_npc();
}

void QuestManager::createQuest()
{
    std::cout<<"Creating Quest"<<std::endl;
    Quest* quest1 = new Quest;
    quest1 -> create_GameWorld();
    activeQuests.push_back(quest1);
}