#include "KNSkillManager.h"

SkillManager::SkillManager(Character *parent, int classID) {
  parent->setSpeed(2);
  if (this->selectClassType(classID) == 0) {
    //Incorrect class type selection
  }
}

SkillManager::~SkillManager() {
  
}

int SkillManager::selectClassType(int classID) {
  /* Will complete soon, but not done yet.
  skills = new Skill*[5];
  skills[4] = NULL;
  Skill **startSkills;

  if (classTypeDatabase->hasClassType(classID)) {
    ClassType *ct = classTypeDatabase->getClassType(classID);
    startSkills = ct->getStartingSkills();
  }
  */
  return 0;
}

int SkillManager::getSelectedClassTypeID() {
  return classID;
}

int SkillManager::getSkillLevel(int skillID) {
  
}

int SkillManager::getTotalLevel() {
  
}

void SkillManager::addExperience(int amount) {
  
}

void SkillManager::applyPowerUp(PowerUp *p) {
  
}

void SkillManager::tickDownPowerUps(double seconds) {
  
}
