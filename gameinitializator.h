/**
 * @file gameinitializator.h
 * @author Kornel Samociuk
 * @date 02.09.2024
 *
 * @brief This class initializes game scene and game logic.
 */

#ifndef GAMEINITIALIZATOR_H
#define GAMEINITIALIZATOR_H

class GameInitializator
{
protected:
    /**
    * @brief Constructor.
    * @par Parameters
    *   None.
    * @par Returns
    *   Nothing.
    */
    GameInitializator();

    /**
    * @brief Virtual function that exists to be overrided by other classes that will need initialization.
    * @par Parameters
    *   None.
    * @par Returns
    *   Nothing.
    */
    virtual void initialize();

    /**
    * @brief Function that initialzies any class that derives from GameInitializator and calls it.
    * @par Parameters
    *   init - pointer of GameInitializator type class.
    * @par Returns
    *   Nothing.
    */
    void initializeMe(GameInitializator *init);
};

#endif // GAMEINITIALIZATOR_H
