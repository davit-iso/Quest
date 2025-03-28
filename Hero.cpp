// #include "Hero.h"
// #include <iostream>
// #include "NPC.h"
#include "header.hpp"

void Hero::displayStats() const
{
    Character::displayStats();
    std::cout<<"Level - "<<static_cast<int>(level)<<std::endl<<"Xp - "<<xp<<std::endl;
}

void Hero::takeDamage(int damage)
{
    Character::takeDamage(damage);
}

void Hero::attack(Character* target)
{
    target -> takeDamage (attackPower + static_cast<int>(item));
}

void Hero::useAbility(Character* target)
{
    target -> takeDamage(attackPower + static_cast<int>(ability));
    set_ab_counter(get_ab_counter() - 3);
}

// void Hero::interact(Character* target)
// {
//     dynamic_cast<NPC*>(target) -> getDialogue();
// }

// std::string Hero::getDialogue() const
// {
//     //return dialogue;
//     return "Hi";
// }

void Hero::set_ab(Ability_h a)
{
    ability = a;
}

void Hero::set_item(Item i)
{
    item = i;
}

void Hero::add_xp(int _xp)
{
    xp += _xp;
    if(level == Level::Level_3)
    {
        std::cout<<"Level - 3\nXp - "<<xp<<std::endl;
        return;
    }
    if(xp >= 250 && xp < 400 && level != Level::Level_2)
    {
        void changeAbility();
        level = Level::Level_2;
        std::cout<<"Level up!\nYour level is - "<<static_cast<int>(level)<<"\nXp - "<<xp<<"\nTo reach the next level, you need to collect 400 points."<<std::endl;
    }
    else if(xp >= 400 && level != Level::Level_3)
    {
        void changeAbility();
        level = Level::Level_3;
        std::cout<<"Level up!\nYour level is - "<<static_cast<int>(level)<<"\nXp - "<<xp<<"\nYou are at the highest level."<<std::endl;
    }
}

void Hero::add_health(int h)
{
    health += h;
    defense += 5;
}

void Warrior::changeAbility()
{
    if(level == Level::Level_2)
    {
        ability = Ability_h::War_Cry;
    }
    else if(level == Level::Level_3)
    {
        item = Item::IGLA;
    }
}

void Mage::changeAbility()
{
    if(level == Level::Level_2)
    {
        item = Item::Dragon_Sword;
    }
    else if(level == Level::Level_3)
    {
        ability = Ability_h::ABRACEDABRA;
    }
}

void Rogue::changeAbility()
{
    if(level == Level::Level_2)
    {
        ability = Ability_h::Silent_Strike;
    }
    else if(level == Level::Level_3)
    {
        item = Item::Kerambit;
    }
}

int Hero::get_ab_counter() const
{
    return ability_counter;
}
void Hero::set_ab_counter(int counter)
{
    ability_counter = counter;
}

void Hero::inc_ab_counter()
{
    ++ability_counter;
}