#include "Border.h"
#include <QPen>
#include <QBrush>

// chama fun borda

Border::Border(QGraphicsScene* scene) {
    createBorders(scene);
}

void Border::createBorders(QGraphicsScene* scene) {
    QPen pen(Qt::black);
    pen.setWidth(1);


    int sceneWidth = 800;
    int sceneHeight = 600;

    // definição das bordas
    QGraphicsRectItem* topBorder = new QGraphicsRectItem(-4, -4, sceneWidth + 8, 4);
    topBorder->setPen(pen);
    topBorder->setBrush(Qt::white);

    QGraphicsRectItem* bottomBorder = new QGraphicsRectItem(-4, sceneHeight, sceneWidth + 8, 4);
    bottomBorder->setPen(pen);
    bottomBorder->setBrush(Qt::white);

    QGraphicsRectItem* leftBorder = new QGraphicsRectItem(-4, 0, 4, sceneHeight);
    leftBorder->setPen(pen);
    leftBorder->setBrush(Qt::white);

    QGraphicsRectItem* rightBorder = new QGraphicsRectItem(sceneWidth, 0, 4, sceneHeight);
    rightBorder->setPen(pen);
    rightBorder->setBrush(Qt::white);

    // chama bordas a cena
    scene->addItem(topBorder);
    scene->addItem(bottomBorder);
    scene->addItem(leftBorder);
    scene->addItem(rightBorder);
}
