#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include "gamescene.h"

class GameView : public QGraphicsView
{
    Q_OBJECT

public:
    GameView();

private:
    GameScene* m_gameScene;
};

#endif // GAMEVIEW_H
