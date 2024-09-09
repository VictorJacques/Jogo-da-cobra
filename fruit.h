#ifndef FRUIT_H
#define FRUIT_H

#include <QGraphicsEllipseItem>


// cria fruta

class Fruit: public QGraphicsEllipseItem{
public:
    Fruit(QGraphicsItem* parent=NULL);
};

#endif // FRUIT_H
