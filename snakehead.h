#ifndef SNAKEHEAD_H
#define SNAKEHEAD_H

#include "SnakeBody.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QList>
#include <QPointF>
#include <QTimer>
// criar cabeça da cobra
class SnakeHead: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    // Construtor
    SnakeHead(QGraphicsItem* parent = NULL);

    // Eventos e métodos públicos
    void keyPressEvent(QKeyEvent* event);
    void elongate();
    void moveBodies();
    void resetGame();
    void increaseSpeed();  // Função para aumentar a velocidade
    QList<SnakeBody*> getSnakeBodies() const;  // Novo método público

private slots:
    void move();  // Slot para mover automaticamente

private:
    QList<SnakeBody*> snakeBodies;
    QPointF prevPos;
    QTimer* timer;
    enum Direction { Up, Down, Left, Right };
    Direction currentDirection;
    int speed;  // Atributo para a velocidade
};

#endif // SNAKEHEAD_H
