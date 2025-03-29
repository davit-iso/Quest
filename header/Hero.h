#ifndef HERO_H
#define HERO_H

// #include "Character.h"
// #include "Interactable.h"
// #include "Combatable.h"
// #include <vector>
#include "header.hpp"

enum class Ability_h{Shadow_step = 15, Silent_Strike = 40, Berserker_Rage = 15, War_Cry = 40, FireBall = 15, ABRACEDABRA = 2000};
enum class Item{Knife = 15, Magic_Wand = 20, AK_47 = 30, Kerambit = 30, Dragon_Sword = 40, IGLA = 60};
enum class Level{Level_1 = 1, Level_2 = 2, Level_3 = 3};

class Hero : public Character, public Interactable, public Combatable 
{
    int ability_counter;
    protected:
    Item item;
    int xp;
    Level level;
    Ability_h ability;
protected:
    void set_ab(Ability_h a);
    void set_item(Item it);
public:
    Hero() = default;
    Hero(const std::string& name, int hp, int def) : Character(name,hp,def), xp(0), level(Level::Level_1),ability_counter(0){};
    virtual ~Hero() = default;
    void displayStats() const override;
    void takeDamage(int damage) override;
    //void interact(Character* target) override;
    std::string getDialogue() const override;
    void attack(Character* target) override;
    void useAbility(Character* target) override;
    virtual void changeAbility() = 0;
    void add_xp(int _xp);
    void add_health(int);
    int get_ab_counter() const;
    void set_ab_counter(int);
    void inc_ab_counter();
    //void level_up();
};

class Warrior : public Hero
{
    public:
    Warrior() = default;
    Warrior(const std::string& name) : Hero(name,150,20)
    {
        set_ab(Ability_h::Berserker_Rage);
        set_item(Item::AK_47);
        attackPower = static_cast<int>(item);
    }
    void changeAbility() override;
};

class Mage : public Hero
{
    public:
    Mage(std::string& name) : Hero(name,100,25)
    {
        set_ab(Ability_h::FireBall);
        set_item(Item::Magic_Wand);
        attackPower = static_cast<int>(item);
    }
    void changeAbility() override;
};

class Rogue : public Hero
{
    public:
    Rogue(std::string& name) : Hero(name,100,20)
    {
        set_ab(Ability_h::Shadow_step);
        set_item(Item::Knife);
        attackPower = static_cast<int>(item);
    }
    void changeAbility() override;
};

#endif