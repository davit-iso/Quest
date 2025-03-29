// #include "NPC.h"
// #include <iostream>
// #include <string>
// #include "Hero.h"
#include "header.hpp"

void NPC::display() const
{
    std::cout<<"Name - "<<name<<std::endl<<"Dialogue - "<<dialogue<<std::endl;
}

// void NPC::interact(Character* target)
// {
//     dynamic_cast<Hero*>(target) -> getDialogue();
// }

std::string NPC::getDialogue() const 
{
    return dialogue;
}

void NPC::set_dialogue(std::string dialogue)
{
    this -> dialogue = dialogue;
}

std::string NPC::get_name()
{
    return name;
}