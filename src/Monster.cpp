// #include "Monster.h"
// #include <iostream>
// #include <string>
#include "header.hpp"

//Monster::Monster(const std::string& name, int health, int def) : Character(name,health,def){};

void Monster::displayStats() const
{
    Character::displayStats();
    //std::cout<<static_cast<std::string>(specialAbility)<<std::endl;
}

void Monster::takeDamage(int damage)
{
    Character::takeDamage(damage);
    if(get_health() <= 0)
    {
        //set_is_alive(false);
        std::cout<<"Monster is killed"<<std::endl;
    }
}

void Monster::attack(Character* target)
{
    target -> takeDamage (attackPower);
}

void Monster::useAbility(Character* target)
{
        target -> takeDamage(attackPower + static_cast<int>(specialAbility));
        set_ab_counter(get_ab_counter_m() - 4);
}

void Monster::set_ab_counter(int c)
{
    ab_counter = c;
}

int Monster::get_ab_counter_m()
{
    return ab_counter;
}