#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <random>

class Utility 
{
    public:
    int getValidatedInput(int min, int max);
    bool saveGameState(const std::string& filename);
    bool loadGameState(const std::string& filename);
    //int getRandomNumber(int min, int max);
};

#endif