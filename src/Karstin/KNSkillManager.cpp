#include "KNSkillManager.h"

//SkillManager::SkillManager(Character *parent = 0, int classID) {
SkillManager::SkillManager(int classID) {  
  if (this->selectClassType(classID) == 0) {
    //Incorrect class type selection
  }
}

SkillManager::~SkillManager() {
  
}

int SkillManager::selectClassType(int classID) {
  
}

int SkillManager::getSelectedClassTypeID() {
  
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
