#include "KNPowerUp.h"

PowerUp::PowerUp(int skillID, double timeInSeconds, int changeAmount) {
  targetSkillID = skillID;
  timeRemaining = timeInSeconds;
  levelChange = changeAmount;
  active = 0;
}

PowerUp::~PowerUp() {
  
}

void PowerUp::activate(int state) {
  if (active == 0) {
    active = 1;
  }
}

int PowerUp::isActive() {
  if (active == 1) return 1;
  return 0;
}

//Return 0 if still active after tick
//Return 1 if time has run out
int PowerUp::tickDown(double seconds) {
  timeRemaining -= seconds;
  if (timeRemaining <= 0) {
    active = 0;
    return 1;
  }
  else return 0;
}

int PowerUp::getLevelChange() {
  return levelChange;
}

int PowerUp::getTargetSkillID() {
  return targetSkillID;
}

double PowerUp::getRemainingTime() {
  return timeRemaining;
}
