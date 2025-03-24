#include "QuestManager.h"
#include <iostream>
#include "Hero.h"

void Quest::create_hero()
{
    Hero* hero = nullptr;
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

void display_start();
void display_current_stage();