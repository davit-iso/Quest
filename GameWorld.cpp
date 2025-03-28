// #include "GameWorld.h"
// #include <iostream>
// #include "Hero.h"
// #include "NPC.h"
#include "header.hpp"

void GameWorld::create_monster()
{
    Monster* mons = nullptr;
    int tmp = -1;
    std::cout<<"What kind of MONSTER do you want to create??"<<std::endl;
    std::cout<<"Choose\nGoblin - 1\nTroll - 2\nDragon - 3"<<std::endl;
    std::cin>>tmp;
    while(true)
    {
        if(tmp == 1)
        {
            std::string ts;
            std::cout<<"Choose name for Goblin"<<std::endl;
            std::cin>>ts;
            mons = new Goblin(ts);
            std::cout<<"The Goblin - "<<ts<<" was created successfully!"<<std::endl;
            break;
        }
        else if(tmp == 2)
        {
            std::string ts;
            std::cout<<"Choose name for Troll"<<std::endl;
            std::cin>>ts;
            mons = new Troll(ts);
            std::cout<<"The Troll - "<<ts<<" was created successfully!"<<std::endl;
            break;
        }
        else if(tmp == 3)
        {
            std::string ts;
            std::cout<<"Choose name for Dragon"<<std::endl;
            std::cin>>ts;
            mons = new Dragon(ts);
            std::cout<<"The Dragon - "<<ts<<" was created successfully!"<<std::endl;
            break;
        }
        std::cout<<"Try again\nGoblin - 1\nTroll - 2\nDragon - 3"<<std::endl;
        std::cin>>tmp;
    }
    monsters.push_back(mons);
}

void GameWorld::create_npc()
{
    NPC* npc = nullptr;
    int tmp = -1;
    std::cout<<"What kind of NPC do you want to create??"<<std::endl;
    std::cout<<"Choose\nVillager - 1\nMerchant - 2\nHealer - 3"<<std::endl;
    std::cin>>tmp;
    while(true)
    {
        if(tmp == 1)
        {
            std::string ts;
            std::cout<<"Choose name for villager"<<std::endl;
            std::cin>>ts;
            npc = new Villager(ts);
            std::cout<<"The Villager - "<<ts<<" was created successfully!"<<std::endl;
            break;
        }
        else if(tmp == 2)
        {
            std::string ts;
            std::cout<<"Choose name for Merchant"<<std::endl;
            std::cin>>ts;
            npc = new Merchant(ts);
            std::cout<<"The Merchant - "<<ts<<" was created successfully!"<<std::endl;
            break;
        }
        else if(tmp == 3)
        {
            std::string ts;
            std::cout<<"Choose name for Healer"<<std::endl;
            std::cin>>ts;
            npc = new Healer(ts);
            std::cout<<"The Healer - "<<ts<<" was created successfully!"<<std::endl;
            break;
        }
        std::cout<<"Try again\nVillager - 1\nMerchant - 2\nHealer - 3"<<std::endl;
        std::cin>>tmp;
    }
    npces.push_back(npc);
}

void Location::display_loc() const
{
    std::cout<<"Location - "<<name<<std::endl;
}

void GameWorld::display_characters() const
{
    std::cout<<"All Characters"<<std::endl;
    for(int i = 0; i < monsters.size(); ++i)
    {
        monsters[i] -> displayStats();
        std::cout<<std::endl;
    }
    for(int i = 0; i < npces.size(); ++i)
    {
        npces[i] -> display();
        std::cout<<std::endl;
    }
}

Location* GameWorld::get_loc()
{
    return location;
}

void GameWorld::display_alive_monsters() const
{
    std::cout<<"Alive Monsters"<<std::endl;
    for(int i{}; i < monsters.size(); ++i)
    {
        if(monsters[i] -> get_health() > 0)
        {
            monsters[i] -> displayStats();
        }
    }
}

Monster* GameWorld::get_monster(std::string name)
{
    for(int i = 0; i < monsters.size(); ++i)
    {
        if(monsters[i] -> get_name() == name && monsters[i] -> get_health() > 0)
        {
            return monsters[i];
        }
        else if(monsters[i] -> get_name() == name && monsters[i] -> get_health() <= 0)
        {
            std::cout<<"The Monster is killed!"<<std::endl;
            return nullptr;
        }
    }
    std::cout<<"Monster not found!!!"<<std::endl;
    return nullptr;
}

int GameWorld::alive_mons_count()
{
    int count = 0;
    for(int i = 0; i < monsters.size(); ++i)
    {
        if(monsters[i] -> get_health() > 0)
        {
            ++count;
        }
    }
    return count;
}

void GameWorld::create_loc()
{
    std::cout<<"Input location name"<<std::endl;
    std::string str;
    std::cin>>str;
    location = new Location(str);
}

GameWorld::~GameWorld()
{
    delete location;
    for(auto m : monsters)
    {
        delete m;
    }
    for(auto n : npces)
    {
        delete n;
    }
}