#include "KNSkill.h"

Skill::Skill(int skillID) {
  ID = skillID;
  level = 0;
}

Skill::Skill(int skillID, int startingLevel) {
  ID = skillID;
  level = startingLevel;
}

Skill::~Skill() {
  
}

int Skill::hasID(int skillID) {
  if (ID == skillID) {
    return 1;
  }
  return 0;
}

int Skill::getLevel() {
  return level;
}

void Skill::levelUp(int amount) {
  level += amount;
  if (level < 0) level = 0;
}

void Skill::setLevel(int value) {
  level = value;
  if (level < 0) level = 0;
}
