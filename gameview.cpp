#include "gameview.h"
#include "gamescene.h"
#include <QKeyEvent>
#include <QApplication>

GameView::GameView()
    : QGraphicsView(), m_gameScene(new GameScene(this)) //Create new GameScene
{
    setScene(m_gameScene);
    resize(m_gameScene->sceneRect().width() + 2, m_gameScene->sceneRect().height() + 2); //+2 to compensate the frame
    setFixedSize(m_gameScene->sceneRect().width() + 2, m_gameScene->sceneRect().height() + 2);
}
