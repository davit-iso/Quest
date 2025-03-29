#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character
{
protected:
    std::string name;
    int health, attackPower, defense;
public:
    Character(std::string name, int hp,  int def) 
    : name(name), health(hp), defense(def){}
    virtual void displayStats() const = 0;
    virtual void takeDamage(int damage) = 0;
    int get_health() const;
    std::string get_name();
    //void set_is_alive(bool);
    virtual ~Character() {};
};
    

#endif