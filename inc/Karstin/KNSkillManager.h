#ifndef __SKILLMANAGER_H__
#define __SKILLMANAGER_H__

#include "KNCharacterDatabase.h"
#include "KNSkill.h"
#include "KNScore.h"
#include "KNPowerUp.h"

class SkillManager {
 public:
  SkillManager();
  ~SkillManager();
  int selectCharacter(int charID);
  int getSelectedCharacter();
  int getSkillLevel(int skillID);
  int getTotalLevel();
  void addExperience(int amount);
  void applyPowerUp(PowerUp *p);
  void tickDownPowerUps(double seconds);
 private:
  Skill skills[];
  CharacterDatabase *characterDatabase;
  Character *selectedCharacter;
  PowerUp *appliedPowerUps;
  Score *score;
  int totalLevel;
  int experience;
  int nextLevelExperience;
};

#endif //SKILLMANAGER_H
