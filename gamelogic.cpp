#include "gamelogic.h"
#include <cstdlib>
#include <ctime>

GameLogic::GameLogic():
    size(5)
{
    initializeMe(this);
}

void GameLogic::initialize()
{
    m_numbers.clear();
    m_grid.clear();
    m_grid.resize(size);

    for(int i = 0; i < size*size; i++)
    {
        m_numbers.push_back(i);
    }

    srand(time(0));

    for(int c = 0; c < size; c++)
    {
        for(int r = 0; r < size; r++)
        {
            int i = rand() % m_numbers.size();
            m_grid[c].push_back(m_numbers.at(i));
            m_numbers.erase(m_numbers.begin() + i);
        }
    }
}

void GameLogic::moveInGrid(int x, int y)
{
    if(x - 1 < 0)
    {
        //Nothing to do
    }
    else if(m_grid[x - 1][y] == 0)
    {
        m_grid[x - 1][y] = m_grid[x][y];
        m_grid[x][y] = 0;
    }

    if(x + 1 >= size)
    {
        //Nothing to do
    }
    else if(m_grid[x + 1][y] == 0)
    {
        m_grid[x + 1][y] = m_grid[x][y];
        m_grid[x][y] = 0;
    }

    if(y - 1 < 0)
    {
        //Nothing to do
    }
    else if(m_grid[x][y - 1] == 0)
    {
        m_grid[x][y - 1] = m_grid[x][y];
        m_grid[x][y] = 0;
    }

    if(y + 1 >= size)
    {
        //Nothing to do
    }
    else if(m_grid[x][y + 1] == 0)
    {
        m_grid[x][y + 1] = m_grid[x][y];
        m_grid[x][y] = 0;
    }
}

bool GameLogic::checkVictory()
{
    for(int c = 0; c < size; c++)
        for(int r = 0; r < size; r++)
            if(m_grid[c][r] != (c + r*size + 1) % (size*size))
                return false;
    return true;
}

int GameLogic::getSize()
{
    return size;
}

std::vector<std::vector<int>> GameLogic::getGrid()
{
    return m_grid;
}
