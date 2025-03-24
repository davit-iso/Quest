#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Interactable.h"

class NPC : public Interactable 
{
    std::string name;
    std::string dialogue;

public:
    NPC(const std::string& name):name(name){};
    void set_dialogue(std::string dialogue);
    void display() const;
    void interact(Character* target);
    std::string getDialogue() const;
};

class Villager : public NPC
{
    public:
    Villager(const std::string& name)
    :NPC(name)
    {
        set_dialogue("Hi, Im villager․ Be careful when fighting monsters, I wish you luck.");
    }
};

class Merchant : public NPC
{
    public:
    Merchant(const std::string& name)
    :NPC(name)
    {
        set_dialogue("Hi, Im merchant Be careful when fighting monsters, I wish you luck.");
    }
};

class Healer : public NPC
{
    public:
    Healer(std::string name)
    :NPC(name)
    {
        set_dialogue("Hi, Im healer Be careful when fighting monsters, I wish you luck.");
    }
};

#endif