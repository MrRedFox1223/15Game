/**
 * @file gamelogic.h
 * @author Kornel Samociuk
 * @date 02.09.2024
 *
 * @brief This class handles game logic and checks if player reached winning condition.
 */

#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "gameinitializator.h"
#include <vector>

class GameLogic: public GameInitializator
{
public:
    /**
    * @brief Constructor, that sets boards size to predetermined int value from 3 to 5.
    * @par Parameters
    *   None.
    * @par Returns
    *   Nothing.
    */
    GameLogic();

    /**
    * @brief Initialization of the game logic.
    * @par Parameters
    *   None.
    * @par Returns
    *   Nothing.
    */
    void initialize() override;

    /**
    * @brief Moving tile values within 2D vector for logic to handle winning condition if reached.
    * @par Parameters
    *   x - columns number of clicked tile [Range: 0, board size]
    *   y - rows number of clicked tile [Range: 0, board size]
    * @par Returns
    *   Nothing.
    */
    void moveInGrid(int x, int y);

    /**
    * @brief Checking if player reached winning condition.
    * @par Parameters
    *   None.
    * @par Returns
    *   true - player reached winning condition.
    *   false - player doesn't reached winning condition.
    */
    bool checkVictory();

    /**
    * @brief Getter of the private size parameter.
    * @par Parameters
    *   None.
    * @par Returns
    *   size - int boards size value.
    */
    int getSize();

    /**
    * @brief Getter of the private 2D vector m_grid.
    * @par Parameters
    *   None.
    * @par Returns
    *   m_grid - 2D vector of ints, holding values of individual tiles on the board.
    */
    std::vector<std::vector<int>> getGrid();

private:
    int size;
    std::vector<int> m_numbers;
    std::vector<std::vector<int>> m_grid;
};

#endif // GAMELOGIC_H
