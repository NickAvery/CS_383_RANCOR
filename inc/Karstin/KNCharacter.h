#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "KNSkill.h"

class Character {
 public:
  static const int CHARACTER_1 = 0;
  static const int CHARACTER_2 = 1;
  static const int CHARACTER_3 = 2;
  Character(int charID, Skill *startSkills);
  ~Character();
  Skill *getStartingSkills();
  int hasID(int charID);
 private:
  int ID;
  Skill *startingSkills;
};

#endif //CHARACTER_H
