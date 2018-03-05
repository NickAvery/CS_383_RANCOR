#include "KNSkillManager.h"
#include <iostream>

SkillManager::SkillManager(Character *parent, int classID) {
  DB = new DataBank();
  classTypeDatabase = new ClassTypeDatabase();
  score = new Score();
  DB->size = new int[] {40, 40};
  totalLevel = 1;
  if (this->selectClassType(classID) == 0) {
    //Incorrect class type selection
  }
  else {
    //Give parent a copy of the data struct
    //parent->setData(DB);
  }
}

SkillManager::~SkillManager() {
  
}

//Sets base defaults for skills based on given classID specifications
//Returns 0 if invalid classID, returns 1 if valid classID
int SkillManager::selectClassType(int classID) {
  ClassType *ct = classTypeDatabase->getClassType(classID);
  if (ct != NULL) {
    healthSkill    = new Skill(Skill::HEALTH,    ct->getSkillLevel(Skill::HEALTH));
    speedSkill     = new Skill(Skill::SPEED,     ct->getSkillLevel(Skill::SPEED));
    damageSkill    = new Skill(Skill::DAMAGE,    ct->getSkillLevel(Skill::DAMAGE));
    fireRateSkill  = new Skill(Skill::FIRERATE,  ct->getSkillLevel(Skill::FIRERATE));
    shotSpeedSkill = new Skill(Skill::SHOTSPEED, ct->getSkillLevel(Skill::SHOTSPEED));
    this->updateDataBank();
    return 1;
  }
  return 0;
}

int SkillManager::getSelectedClassTypeID() {
  return classID;
}

int SkillManager::getSkillLevel(int skillID) {
  switch(skillID) {
  case(Skill::HEALTH):
    return healthSkill->getLevel();
  case(Skill::SPEED):
    return speedSkill->getLevel();
  case(Skill::DAMAGE):
    return damageSkill->getLevel();
  case(Skill::FIRERATE):
    return fireRateSkill->getLevel();
  case(Skill::SHOTSPEED):
    return shotSpeedSkill->getLevel();
  default:
    return -1;
  };  
}

int SkillManager::getTotalLevel() {
  return totalLevel;
}

void SkillManager::addExperience(int amount) {
  
}

void SkillManager::applyPowerUp(PowerUp *p) {
  
}

void SkillManager::tickDownPowerUps(double seconds) {

}

void SkillManager::updateDataBank() {
  DB->totalHealth = healthSkill->getLevel();
  DB->speed = speedSkill->getLevel();
  DB->damage = damageSkill->getLevel();
  DB->fireRate = fireRateSkill->getLevel();
  DB->shotSpeed = shotSpeedSkill->getLevel();
}
