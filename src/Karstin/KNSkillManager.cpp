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
  switch(classID) {
  case(Skill::WARRIOR):
    break;
  case(Skill::RANGER):
    break;
  case(Skill::DR_BC):
    break;
  default:
    break;
  };
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
