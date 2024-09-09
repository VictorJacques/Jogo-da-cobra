#include "Score.h"
#include <QFont>
#include <QGraphicsTextItem>

Score::Score(QGraphicsItem* parent) : QGraphicsTextItem(parent), score(0) {
    setPlainText(QString("Pontos: %1").arg(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 16));
    setPos(675, -40);
}

void Score::increase(int points) {
    score += points;
    setPlainText(QString("Score: %1").arg(score));
}

void Score::reset() {
    score = 0;
    setPlainText(QString("Score: %1").arg(score));
}

int Score::getScore() const {
    return score;
}
