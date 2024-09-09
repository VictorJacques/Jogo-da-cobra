#include "SnakeHead.h"
#include <QBrush>
#include "Fruit.h"
#include "SnakeBody.h"
#include "Game.h"
#include <QTimer>
#include <QRandomGenerator>

extern Game* game;

SnakeHead::SnakeHead(QGraphicsItem *parent) : QGraphicsRectItem(parent), speed(250) {
    // Cria a cabeça da cobra
    setRect(0, 0, 50, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(QColor(43, 51, 24, 200));
    setBrush(brush);
    setFlag(QGraphicsItem::ItemIsFocusable, true);
    setFocus();

    //  direção inicial
    currentDirection = Right;


    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SnakeHead::move);
    timer->start(speed);

    // adiciona a parte inicial do corpo da cobra
    SnakeBody* b1 = new SnakeBody();
    b1->setPos(0, 50);
    game->scene->addItem(b1);
    snakeBodies.prepend(b1);
}

void SnakeHead::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Up && currentDirection != Down) {
        currentDirection = Up;
    }
    else if (event->key() == Qt::Key_Down && currentDirection != Up) {
        currentDirection = Down;
    }
    else if (event->key() == Qt::Key_Right && currentDirection != Left) {
        currentDirection = Right;
    }
    else if (event->key() == Qt::Key_Left && currentDirection != Right) {
        currentDirection = Left;
    }

    if (event->key() == Qt::Key_R) {
        resetGame();
    }
}

void SnakeHead::move() {
    prevPos = pos();
    int xPos = x();
    int yPos = y();

    if (currentDirection == Up) {
        yPos -= boundingRect().height();
    }
    else if (currentDirection == Down) {
        yPos += boundingRect().height();
    }
    else if (currentDirection == Right) {
        xPos += boundingRect().width();
    }
    else if (currentDirection == Left) {
        xPos -= boundingRect().width();
    }

    if (xPos >= 800) {  // Borda direita
        xPos = 0;
    }
    else if (xPos < 0) {  // Borda esquerda
        xPos = 800 - boundingRect().width();
    }

    if (yPos >= 600) {  // Borda inferior
        yPos = 0;
    }
    else if (yPos < 0) {  // Borda superior
        yPos = 600 - boundingRect().height();
    }

    setPos(xPos, yPos);
    moveBodies();

    for (int i = 0; i < snakeBodies.size(); ++i) {
        if (this->collidesWithItem(snakeBodies[i])) {
            timer->stop();  // Para o movimento se houver colisão
            return;
        }
    }

    QList<QGraphicsItem*> cItems = collidingItems();
    for (size_t i = 0, n = cItems.size(); i < n; ++i) {
        if (typeid(*cItems[i]) == typeid(Fruit)) {
            elongate();
            game->increaseScore(10);
            game->createRandomFruit(this);
            game->scene->removeItem(cItems[i]);
            delete cItems[i];

            // Aumenta a velocidade
            increaseSpeed();
        }
    }
}

void SnakeHead::elongate() {
    SnakeBody* body = new SnakeBody();
    snakeBodies.prepend(body);
    body->setPos(-200, -200);
    game->scene->addItem(body);
}

void SnakeHead::moveBodies() {
    for (size_t i = snakeBodies.size() - 1; i > 0; --i) {
        snakeBodies[i]->setPos(snakeBodies[i - 1]->pos());
    }
    if (!snakeBodies.isEmpty()) {
        snakeBodies.first()->setPos(prevPos);
    }
}

void SnakeHead::resetGame() {
    timer->stop();

    while (!snakeBodies.isEmpty()) {
        QGraphicsItem* body = snakeBodies.takeFirst();
        game->scene->removeItem(body);
        delete body;
    }

    setPos(400, 300);

    for (int i = 1; i <= 2; ++i) {
        SnakeBody* body = new SnakeBody();
        body->setPos(400 - i * 50, 300);
        snakeBodies.append(body);
        game->scene->addItem(body);
    }

    currentDirection = Right;
    timer->start(speed);
    game->score->reset();
}

void SnakeHead::increaseSpeed() {
    speed = qMax(125, speed - 10);
    timer->setInterval(speed);
}

QList<SnakeBody*> SnakeHead::getSnakeBodies() const {
    return snakeBodies;
}
