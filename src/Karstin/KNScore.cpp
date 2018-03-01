#include "KNScore.h"

Score::Score() {
  score = 0;
}

Score::~Score() {
  
}

int Score::getScore() {
  return score;
}

void Score::calculateScore(int experience) {
  score = experience;
  //Send score to server with player name?
}
