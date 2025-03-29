#include "header.hpp"

void Character::displayStats() const
{
    std::cout<<"Name - "<<name<<std::endl<<"Health - "<<health<<std::endl<<"Defense - "<<defense<<std::endl<<"Attack power - "<<attackPower<<std::endl;
}

void Character::takeDamage(int damage)
{
    int tmp = damage - defense;
    if(tmp > 0)
    {
        health = health - tmp;
    }
    else
    {
        std::cout<<"Hahaha"<<std::endl;
    }

}

int Character::get_health() const
{
    return health;
}

std::string Character::get_name()
{
    return name;
}