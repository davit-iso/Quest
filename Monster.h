#ifndef MONSTER_H
#define MONSTER_H

// #include "Character.h"
// #include "Combatable.h"
#include "header.hpp"

enum class Ability{Explosive_Trap = 25 , Troll_Smash = 30 , FIREBREATH = 50};

class Monster : public Character, public Combatable 
{
    int ab_counter;
    Ability specialAbility;
protected:
    virtual void set_spab(Ability ab){};
public:
    Monster(const std::string& name, int health, int def):Character(name,health,def),ab_counter(0){};
    void displayStats() const override;
    void takeDamage(int damage) override;
    void attack(Character* target) override;
    void useAbility(Character* target) override;
    void set_ab_counter(int);
    int get_ab_counter_m();
    ~Monster() = default;
};

class Goblin : public Monster
{
    public:
    Goblin(const std::string& name)
    :Monster(name,100,10)
    {
        set_spab(Ability::Explosive_Trap);
        attackPower = 30;
    }
};

class Troll : public Monster
{
    public:
    Troll(const std::string& name)
    :Monster(name,110,15)
    {
        set_spab(Ability::Troll_Smash);
        attackPower = 25;
    }
};

class Dragon : public Monster
{
    public:
    Dragon(const std::string& name)
    :Monster(name,150,30)
    {
        set_spab(Ability::FIREBREATH);
        attackPower = 50;
    }
};

#endif