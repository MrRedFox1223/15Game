/**
 * @file pixmaptile.h
 * @author Kornel Samociuk
 * @date 02.09.2024
 *
 * @brief This class holds data about visual position and appearance of individual tile.
 */

#ifndef PIXMAPTILE_H
#define PIXMAPTILE_H

#include <QGraphicsPixmapItem>

class PixmapTile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    /**
    * @brief Constructor, that sets parent of this QObject.
    * @par Parameters
    *   parent - pointer to QObject that will represent tile.
    * @par Returns
    *   Nothing.
    */
    PixmapTile(QObject *parent = nullptr);
};

#endif // PIXMAPTILE_H
