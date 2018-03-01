#ifndef __SCORE_H__
#define __SCORE_H__

class Score {
 public:
  Score();
  ~Score();
  int getScore();
  void calculateScore(int experience);
 private:
  int score;
};

#endif //SCORE_H
