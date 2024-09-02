#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gameinitializator.h"
#include <vector>

class GameLogic: public GameInitializator
{
public:
    GameLogic();

    void initialize() override;
    void moveInGrid(int x, int y);
    bool checkVictory();
    int getSize();
    std::vector<std::vector<int>> getGrid();

private:
    int size;
    std::vector<int> m_numbers;
    std::vector<std::vector<int>> m_grid;
};

#endif // GAMELOGIC_H
