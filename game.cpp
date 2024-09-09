#include "Game.h"
#include "SnakeHead.h"
#include "Fruit.h"
#include "Border.h"
#include <QBrush>
#include <QRandomGenerator>

// alinha posição a grade
QPointF getRandomPosition(int width, int height, int itemWidth, int itemHeight) {
    int xCount = width / itemWidth; // posições possíveis no eixo X
    int yCount = height / itemHeight; //posições possíveis no eixo Y

    int x = QRandomGenerator::global()->bounded(xCount) * itemWidth;
    int y = QRandomGenerator::global()->bounded(yCount) * itemHeight;
    return QPointF(x, y);
}

// Colisão da fruta vs cobra
bool isPositionOccupiedBySnake(QPointF position, SnakeHead* snakeHead) {
    // fruta vs cabeça
    if (snakeHead->pos() == position) {
        return true;
    }

    // Vfruta vs corpo
    for (SnakeBody* bodySegment : snakeHead->getSnakeBodies()) {
        if (bodySegment->pos() == position) {
            return true;
        }
    }

    return false;
}

Game::Game(QWidget *parent) : QGraphicsView(parent) {
    setupScene();
}

void Game::setupScene() {
    scene = new QGraphicsScene(-25, -40, 850, 650);
    setScene(scene);

    QBrush brush;
    brush.setStyle(Qt::Dense2Pattern);
    brush.setColor(QColor(173, 204, 96, 255));
    setBackgroundBrush(brush);

    Border* border = new Border(scene);

    // pontuação
    score = new Score();
    scene->addItem(score);
}

void Game::start() {
    SnakeHead* snakeHead = new SnakeHead();
    scene->addItem(snakeHead);
    snakeHead->setFocus();

    createRandomFruit(snakeHead);  // cria uma fruta em local aleatório sem que coincida com a cobra
}

void Game::createRandomFruit(SnakeHead* snakeHead) {
    Fruit* f1 = new Fruit();
    QPointF randomPos;


    do {
        randomPos = getRandomPosition(scene->sceneRect().width(), scene->sceneRect().height(), f1->boundingRect().width(), f1->boundingRect().height());
    } while (isPositionOccupiedBySnake(randomPos, snakeHead));

    f1->setPos(randomPos);
    scene->addItem(f1);
}

void Game::increaseScore(int points) {
    score->increase(points);
}
