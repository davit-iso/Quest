#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
#include "Combatable.h"

enum class Ability{Explosive_Trap = 25 , Troll_Smash = 30 , FIREBREATH = 50};

class Monster : public Character, public Combatable 
{
    Ability specialAbility;
protected:
    void set_spab(Ability ab);
public:
    Monster(const std::string& name, int health, int at, int def):Character(name,health,at,def){};
    void displayStats() const override;
    void takeDamage(int damage) override;
    void attack(Character* target) override;
    void useAbility(Character* target) override;

};

class Goblin : public Monster
{
    public:
    Goblin(const std::string& name)
    :Monster(name,100,30,10)
    {
        set_spab(Ability::Explosive_Trap);
    }
};

class Troll : public Monster
{
    public:
    Troll(const std::string& name)
    :Monster(name,110,25,15)
    {
        set_spab(Ability::Troll_Smash);
    }
};

class Dragon : public Monster
{
    public:
    Dragon(const std::string& name)
    :Monster(name,150,50,30)
    {
        set_spab(Ability::FIREBREATH);
    }
};

#endif