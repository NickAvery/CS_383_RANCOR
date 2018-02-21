#ifndef __SKILL_H__
#define __SKILL_H__

class Skill {
 public:
  static const int STRENGTH = 0;
  static const int SPEED = 1;
  static const int ACCURACY = 2;
  static const int RESILIENCE = 3;
  Skill(int skillID);
  Skill(int skillID, int startingLevel);
  ~Skill();
  int hasID(int skillID);
  int getLevel();
  void levelUp(int amount);
  void setLevel(int value);
 private:
  int level;
  int ID;
};

#endif //SKILL_H
