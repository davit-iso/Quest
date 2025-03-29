#include "header.hpp"

int main()
{
    QuestManager* manager = new QuestManager();
    manager -> start_game();
    delete manager;
    return 0;
}