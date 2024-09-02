/**
 * @file gamescene.h
 * @author Kornel Samociuk
 * @date 02.09.2024
 *
 * @brief This class handles visualization of the game and interaction logic with the player.
 */

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
    /**
    * @brief Constructor, that sets values needed to load reasources of the game.
    * @par Parameters
    *   parent - pointer to QObject that will be a place to show the game scene.
    * @par Returns
    *   Nothing.
    */
    GameScene(QObject *parent = nullptr);

private:
    GameLogic m_game;
    int m_tileWidth;
    QPixmap m_mainTilePixmap;
    QPixmap m_bgPixmap;
    QPixmap m_winPixmap;
    QGraphicsPixmapItem *m_winScreen;
    std::vector<QPixmap> m_tilesPixmaps;
    std::vector<std::vector<PixmapTile *>> m_pixmapTiles;
    int m_clickedX;
    int m_clickedY;

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
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // GAMESCENE_H
