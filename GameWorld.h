#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include <vector>
#include <string>
#include "Character.h"
#include "Hero.h"
#include "Monster.h"

enum class Locations {Undefined,Desert, Forest, Mountain};

class Location
{
    Locations loc_type = Locations::Undefined;
    std::string name;
    public:
    Location(std::string name):name(name){};
    ~Location();
};

class GameWorld 
{
    std::vector<Location*> locations;
    std::vector<Monster*> monsters;
    std::vector<NPC*> npces;
public:
    GameWorld();
    ~GameWorld();
    void movePlayer(int locationIndex);
    //void triggerEncounter();
    void create_monster();
    void create_npc();
    //void ad_character(Character* charac);
    //void display_start();
    //void display_current_stage();
};

#endif