#ifndef PIXMAPTILE_H
#define PIXMAPTILE_H

#include <QGraphicsPixmapItem>

class PixmapTile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    PixmapTile(QObject *parent = nullptr);
};

#endif // PIXMAPTILE_H
