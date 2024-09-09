#include "Fruit.h"
#include <QBrush>


// desenha fruta

Fruit::Fruit(QGraphicsItem *parent){
    setRect(0,0,50,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}
