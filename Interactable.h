#ifndef INTERACTABLE_H
#define INTERACTABLE_H

#include "Character.h"
#include <string>

class Interactable 
{
public:
    virtual void interact(Character* target) = 0;
    virtual std::string getDialogue() const = 0;
    virtual ~Interactable() = default;
};

#endif