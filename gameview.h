/**
 * @file gameview.h
 * @author Kornel Samociuk
 * @date 02.09.2024
 *
 * @brief This class sets up QObject that will be a game window.
 */

#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include "gamescene.h"

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    /**
    * @brief Constructor, that creates and sets up the game scene.
    * @par Parameters
    *   None.
    * @par Returns
    *   Nothing.
    */
    GameView();

private:
    GameScene* m_gameScene;
};

#endif // GAMEVIEW_H
