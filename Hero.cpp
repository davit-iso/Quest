#include "Hero.h"
#include <iostream>
#include "NPC.h"

void Hero::displayStats() const
{
    Character::displayStats();
    std::cout<<"Level - "<<level<<std::endl<<"Xp - "<<xp<<std::endl;
}

void Hero::takeDamage(int damage)
{
    Character::takeDamage(damage);
    if(get_health() <= 0)
    {
        //game over
    }
}

void Hero::attack(Character* target)
{
    target -> takeDamage (attackPower + static_cast<int>(item));
    if(target -> get_health() == 0)
    {
        
    }
}

void Hero::useAbility(Character* target)
{
    target -> takeDamage(attackPower + static_cast<int>(ability));
    if(get_health() == 0)
    {
        
    }    
}

void Hero::interact(Character* target)
{
    dynamic_cast<NPC*>(target) -> getDialogue();
}

std::string Hero::getDialogue() const
{
    //return dialogue;
}

void Warrior::changeAbility()
{
    
}

void Mage::changeAbility()
{
    
}

void Rogue::changeAbility()
{
    
}