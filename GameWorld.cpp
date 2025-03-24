#include "GameWorld.h"
#include <iostream>
#include "Hero.h"
#include "NPC.h"

// void GameWorld::create_hero()
// {
//     Hero* hero = nullptr;
//     int tmp = -1;
//     std::cout<<"What kind of HERO do you want to create??"<<std::endl;
//     std::cout<<"Choose\nWarior - 1\nMage - 2\nRogue - 3"<<std::endl;
//     std::cin>>tmp;
//     while(true)
//     {
//         if(tmp == 1)
//         {
//             std::string ts;
//             std::cout<<"Choose name for warrior"<<std::endl;
//             std::cin>>ts;
//             hero = new Warrior(ts);
//             std::cout<<"The Warrior - "<<ts<<" was created successfully!"<<std::endl;
//             break;
//         }
//         else if(tmp == 2)
//         {
//             std::string ts;
//             std::cout<<"Choose name for mage"<<std::endl;
//             std::cin>>ts;
//             hero = new Mage(ts);
//             std::cout<<"The Mage - "<<ts<<" was created successfully!"<<std::endl;
//             break;
//         }
//         else if(tmp == 3)
//         {
//             std::string ts;
//             std::cout<<"Choose name for rogue"<<std::endl;
//             std::cin>>ts;
//             hero = new Rogue(ts);
//             std::cout<<"The Rogue - "<<" was created successfully!"<<std::endl;
//             break;
//         }
//         std::cout<<"Try again\nWarior - 1\nMage - 2\nRogue - 3"<<std::endl;
//         std::cin>>tmp;
//     }
// }

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

