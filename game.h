#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Score.h"

class SnakeHead;
class Fruit;

class Game : public QGraphicsView {
    Q_OBJECT
public:
    Game(QWidget *parent = nullptr);

    void start();
    void increaseScore(int points);
    void createRandomFruit(SnakeHead* snakeHead);

    QGraphicsScene* scene;
    Score* score;

private:
    void setupScene();
};

#endif // GAME_H
