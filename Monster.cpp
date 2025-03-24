#include "Monster.h"
#include <iostream>
#include <string>

Monster::Monster(const std::string& name, int health, int at, int def) : Character(name,health,at,def){};

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
}