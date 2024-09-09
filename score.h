#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
//cria pontuação
class Score : public QGraphicsTextItem {
public:
    Score(QGraphicsItem* parent = nullptr);

    void increase(int points);
    void reset();
    int getScore() const;

private:
    int score;
};

#endif // SCORE_H
