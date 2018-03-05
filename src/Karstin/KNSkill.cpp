#include "KNSkill.h"

Skill::Skill(int skillID) {
  ID = skillID;
  level = 0;
  mod = 0;
}

Skill::Skill(int skillID, int startingLevel) {
  ID = skillID;
  level = startingLevel;
  mod = 0;
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
  return level + mod;
}

void Skill::levelUp(int amount) {
  mod += amount;
  if (level + mod < 0) mod = -level;
}

void Skill::setLevel(int value) {
  level = value;
  if (level + mod < 0) mod = -level;
}
