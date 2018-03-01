#ifndef __POWERUP_H__
#define __POWERUP_H__

class PowerUp {
 public:
  PowerUp(int skillID, double timeInSeconds, int changeAmount);
  ~PowerUp();
  void activate(int state);
  int isActive();
  int tickDown(double seconds);
  int getLevelChange();
  int getTargetSkillID();
  double getRemainingTime();
 private:
  int targetSkillID;
  double timeRemaining;
  int levelChange;
  int active;
};

#endif //POWERUP_H
