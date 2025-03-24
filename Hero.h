#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include "Interactable.h"
#include "Combatable.h"
#include <vector>

enum class Ability_h{Shadow_step = 15, Silent_Strike = 40, Berserker_Rage = 15, War_Cry = 40, FireBall = 15, ABRACEDABRA = 2000};
enum class Item{Knife = 15, Magic_Wand = 20, AK_47 = 30, Kerambit = 30, Dragon_Sword = 40, IGLA = 60};

class Hero : public Character, public Interactable, public Combatable 
{
    Item item;
    int xp;
    int level;
    Ability_h ability;
protected:
    void set_ab(Ability_h a);
    void set_item(Item it);
public:
    Hero(const std::string& name, int hp, int at, int def) : Character(name,hp,at,def), xp(0), level(0){};
    ~Hero();
    void displayStats() const override;
    void takeDamage(int damage) override;
    void interact(Character* target) override;
    std::string getDialogue() const override;
    void attack(Character* target) override;
    void useAbility(Character* target) override;
    virtual void changeAbility() = 0;
};

class Warrior : public Hero
{
    public:
    Warrior(const std::string& name) : Hero(name,150,0,20)
    {
        set_ab(Ability_h::Berserker_Rage);
        set_item(Item::AK_47);
    }
    void changeAbility() override;
};

class Mage : public Hero
{
    public:
    Mage(std::string& name) : Hero(name,150,0,20)
    {
        set_ab(Ability_h::FireBall);
        set_item(Item::Magic_Wand);
    }
    void changeAbility() override;
};

class Rogue : public Hero
{
    public:
    Rogue(std::string& name) : Hero(name,150,0,20)
    {
        set_ab(Ability_h::Shadow_step);
        set_item(Item::Knife);
    }
    void changeAbility() override;
};

#endif