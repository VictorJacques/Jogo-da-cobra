#ifndef BORDER_H
#define BORDER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>


// criador de bordas
class Border : public QGraphicsRectItem {
public:
    Border(QGraphicsScene* scene);

private:
    void createBorders(QGraphicsScene* scene);
};

#endif // BORDER_H
