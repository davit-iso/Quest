#ifndef GAMEWORLD_H
#define GAMEWORLD_H

// #include <vector>
// #include <string>
// #include "Character.h"
// #include "Hero.h"
// #include "Monster.h"
// #include "NPC.h"
#include "header.hpp"
//enum class Locations {Undefined,Desert, Forest, Mountain};
class NPC;
class Monster;

class Location
{
    std::string name;
    public:
    Location(std::string name):name(name){};
    void display_loc() const;
    ~Location() = default;
};

class GameWorld 
{
    Location* location;
    std::vector<Monster*> monsters;
    std::vector<NPC*> npces;
public:
    GameWorld() = default;
    virtual ~GameWorld();
    //void movePlayer(int locationIndex);
    //void triggerEncounter();
    void create_monster();
    void create_npc();
    void create_loc();
    void display_characters() const;
    Location* get_loc();
    void display_alive_monsters() const;
    int alive_mons_count();
    Monster* get_monster(std::string name);
    //void ad_character(Character* charac);
    //void display_start();
    //void display_current_stage();
};

#endif