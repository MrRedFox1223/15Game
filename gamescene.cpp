#include "gamescene.h"
#include "qapplication.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, m_tileWidth(64), PATH_TO_TILES(":/resources/img/tiles5.png"), PATH_TO_BG(":/resources/img/bg5.png"),
    PATH_TO_WIN(":/resources/img/win.jpg")
{
    loadPixmap();
    setSceneRect(0, 0, m_game.getSize()*m_tileWidth, m_game.getSize()*m_tileWidth);
    initializeMe(this);
}

void GameScene::loadPixmap()
{
    m_mainTilePixmap.load(PATH_TO_TILES);

    for(int i = 0; i < m_game.getSize() * m_game.getSize() ; i++)
        m_tilesPixmap.push_back(m_mainTilePixmap.copy(i*m_tileWidth, 0, m_tileWidth, m_tileWidth));

    m_bgPixmap.load(PATH_TO_BG);
    m_winPixmap.load(PATH_TO_WIN);
}

void GameScene::initialize()
{
    clear();
    QGraphicsPixmapItem *bgItem = new QGraphicsPixmapItem(m_bgPixmap);
    bgItem->setZValue(-1);
    addItem(bgItem);

    m_winScreen = new QGraphicsPixmapItem(m_winPixmap.scaled(m_game.getSize()*m_tileWidth, m_game.getSize()*m_tileWidth));

    m_pixmapTiles.resize(m_game.getSize());

    for (int c = 0; c < m_game.getSize(); c++)
    {
        for (int r = 0; r < m_game.getSize(); r++)
        {
            int n = m_game.getGrid()[c][r];
            m_pixmapTiles[c].push_back(new PixmapTile(this)); //Create tile
            m_pixmapTiles[c][r]->setPixmap(m_tilesPixmap[n]); //Set how tile looks (number)
            m_pixmapTiles[c][r]->setPos(c * m_tileWidth, r * m_tileWidth); //Set tile position
            addItem(m_pixmapTiles[c][r]); //Show tile
        }
    }
}

void GameScene::moveTile()
{
    if(m_clickedX - 1 < 0)
    {
        //Nothing to do
    }
    else if(m_game.getGrid()[m_clickedX - 1][m_clickedY] == 0)
    {
        PixmapTile *m_pixeplaTile = m_pixmapTiles[m_clickedX][m_clickedY];
        m_pixeplaTile->setPos(m_pixeplaTile->pos().x() - m_tileWidth, m_pixeplaTile->pos().y());
        m_game.moveInGrid(m_clickedX, m_clickedY);
    }

    if(m_clickedX + 1 >= m_game.getSize())
    {
        //Nothing to do
    }
    else if(m_game.getGrid()[m_clickedX + 1][m_clickedY] == 0)
    {
        PixmapTile *m_pixeplaTile = m_pixmapTiles[m_clickedX][m_clickedY];
        m_pixeplaTile->setPos(m_pixeplaTile->pos().x() + m_tileWidth, m_pixeplaTile->pos().y());

        m_game.moveInGrid(m_clickedX, m_clickedY);
    }

    if(m_clickedY - 1 < 0)
    {
        //Nothing to do
    }
    else if(m_game.getGrid()[m_clickedX][m_clickedY - 1] == 0)
    {
        PixmapTile *m_pixeplaTile = m_pixmapTiles[m_clickedX][m_clickedY];
        m_pixeplaTile->setPos(m_pixeplaTile->pos().x(), m_pixeplaTile->pos().y() - m_tileWidth);

        m_game.moveInGrid(m_clickedX, m_clickedY);
    }

    if(m_clickedY + 1 >= m_game.getSize())
    {
        //Nothing to do
    }
    else if(m_game.getGrid()[m_clickedX][m_clickedY + 1] == 0)
    {
        PixmapTile *m_pixeplaTile = m_pixmapTiles[m_clickedX][m_clickedY];
        m_pixeplaTile->setPos(m_pixeplaTile->pos().x(), m_pixeplaTile->pos().y() + m_tileWidth);

        m_game.moveInGrid(m_clickedX, m_clickedY);
    }

    updatePixmaps();

    if(m_game.checkVictory())
        victory();
}

void GameScene::updatePixmaps()
{
    for (int c = 0; c < m_game.getSize() ; c++)
    {
        for (int r = 0; r < m_game.getSize(); r++)
        {
            int n = m_game.getGrid()[c][r];
            m_pixmapTiles[c][r]->setPixmap(m_tilesPixmap[n]);
            m_pixmapTiles[c][r]->setPos(c * m_tileWidth, r * m_tileWidth);
        }
    }
}

void GameScene::victory()
{
    if (!m_winScreen->isActive())
        addItem(m_winScreen);
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        QPointF clickedPos =  event->scenePos();
        m_clickedX = static_cast<int>(clickedPos.x()) / m_tileWidth;
        m_clickedY = static_cast<int>(clickedPos.y()) / m_tileWidth;

        moveTile();
    }
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Escape:
    {
        QApplication::instance()->quit();
    }
        break;
    }

    QGraphicsScene::keyPressEvent(event);
}
