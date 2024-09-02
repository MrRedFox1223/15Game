#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <vector>
#include "gamelogic.h"
#include "pixmaptile.h"

class GameScene: public QGraphicsScene, public GameInitializator
{
    Q_OBJECT
public:
    GameScene(QObject *parent = nullptr);

private:
    GameLogic m_game;
    int m_tileWidth;
    QPixmap m_mainTilePixmap;
    QPixmap m_bgPixmap;
    QPixmap m_winPixmap;
    QGraphicsPixmapItem *m_winScreen;
    std::vector<QPixmap> m_tilesPixmap;
    std::vector<std::vector<PixmapTile *>> m_pixmapTiles;
    int m_clickedX;
    int m_clickedY;
    int test;

    //Visualization data
    QString PATH_TO_TILES;
    QString PATH_TO_BG;
    QString PATH_TO_WIN;

    void initialize() override;
    void loadPixmap();
    void moveTile();
    void updatePixmaps();
    void victory();

    //From QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

};

#endif // GAMESCENE_H
