#include "KNSkillManager.h"
#include <iostream>
#include <cstdlib>

using namespace std;

SkillManager::SkillManager(Character *parent, int classID) {
  DB = new DataBank();
  classTypeDatabase = new ClassTypeDatabase();
  score = new Score();
  DB->size[0] = 40;
  DB->size[1] = 40;
  totalLevel = 1;
  experience = 0;
  nextLevelExperience = 1000;
  growthMultiplier = 1.15;
  if (this->selectClassType(classID) == 0) {
    //Incorrect class type selection
  }
  else {
    //Give parent a copy of the data struct
    parent->setPlayerStats(DB);
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
    DB->currentHealth = DB->totalHealth;
    return 1;
  }
  return 0;
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
  experience += amount;
  if (experience >= nextLevelExperience) {
    totalLevel++;
    nextLevelExperience += nextLevelExperience * growthMultiplier;
    cout << "LEVEL UP (" << totalLevel << ")!\nnextLevelExperience: " << nextLevelExperience << endl;
    healthSkill->levelUp(1);
    DB->currentHealth += 10;
    //level up 1-2 random skills
    int choice = rand() % 4;
    switch(choice) {
    case(0):
      damageSkill->levelUp(1);
      break;
    case(1):
      speedSkill->levelUp(1);
      break;
    case(2):
      fireRateSkill->levelUp(1);
      break;
    case(3):
      shotSpeedSkill->levelUp(1);
      break;
    default:
      break;
    };
    this->updateDataBank();
    
    cout << "DB contents:" << endl;
    cout << "totalHealth:   " << DB->totalHealth << endl;
    cout << "currentHealth: " << DB->currentHealth << endl;
    cout << "damage:        " << DB->damage << endl;
    cout << "speed:         " << DB->speed << endl;
    cout << "fireRate:      " << DB->fireRate << endl;
    cout << "shotSpeed:     " << DB->shotSpeed << endl;
  }
}

void SkillManager::applyPowerUp(PowerUp *p) {
  
}

void SkillManager::tickDownPowerUps(double seconds) {

}

void SkillManager::updateDataBank() {
  DB->totalHealth = 100+(10*(healthSkill->getLevel()-1));
  DB->speed = speedSkill->getLevel();
  DB->damage = damageSkill->getLevel();
  DB->fireRate = fireRateSkill->getLevel();
  DB->shotSpeed = shotSpeedSkill->getLevel();
}
