/* KNSkillManager.cpp
 * 
 * Implementation file for SkillManager class.
 * 
 * J Karstin Neill      4.24.18
 */

#include "KNSkillManager.h"
#include <iostream>
#include <cstdlib>

using namespace std;

SkillManager::SkillManager(Character *parent, int classID)
{
  DB = new DataBank();
  classTypeDatabase = new ClassTypeDatabase();
  score = 0;
  DB->size[0] = 40;
  DB->size[1] = 40;
  totalLevel = 1;
  experience = 0;
  nextLevelExperience = 100;
  growthMultiplier = 1.15;
  itemDatabase = new ItemDatabase();
  if (this->selectClassType(classID))
  {
    //Give parent a copy of the data struct
    parent->setPlayerStats(DB);
  }
  else
  {
    //Incorrect class type selection
  }
}

SkillManager::~SkillManager()
{
  
}

//Sets base defaults for skills based on given classID specifications
//Returns false if invalid classID, returns true if valid classID
bool SkillManager::selectClassType(int classID)
{
  ClassType *ct = classTypeDatabase->getClassType(classID);
  if (ct != NULL)
  {
    healthSkill    = new Skill(Skill::HEALTH,    ct->getSkillLevel(Skill::HEALTH));
    speedSkill     = new Skill(Skill::SPEED,     ct->getSkillLevel(Skill::SPEED));
    damageSkill    = new Skill(Skill::DAMAGE,    ct->getSkillLevel(Skill::DAMAGE));
    fireRateSkill  = new Skill(Skill::FIRERATE,  ct->getSkillLevel(Skill::FIRERATE));
    shotSpeedSkill = new Skill(Skill::SHOTSPEED, ct->getSkillLevel(Skill::SHOTSPEED));
    this->updateDataBank();
    DB->currentHealth = DB->totalHealth;
    return true;
  }
  return false;
}

int SkillManager::getSkillLevel(int skillID)
{
  switch(skillID)
  {
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

int SkillManager::getLevel()
{
  return totalLevel;
}

void SkillManager::addExperience(int amount)
{
  experience += amount;
  if (experience >= nextLevelExperience)
  {
    this->levelUp(1);
  }
  this->calculateScore();
}

void SkillManager::levelUp(int levels)
{
  totalLevel += levels;
  for (int i=0; i < levels; i++)
  {
    nextLevelExperience += nextLevelExperience * growthMultiplier;
    cout << "LEVEL UP (" << totalLevel << ")!\nnextLevelExperience: " << nextLevelExperience << endl;
    healthSkill->levelUp(1);
    DB->currentHealth += 10;
    //level up 1-2 random skills
    int choice = rand() % 4;
    switch(choice)
    {
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
  }
  this->updateDataBank();
  //Temporary
  this->printDataBank();
}

bool SkillManager::addItem(int ref)
{
  //Search ItemDatabase for matching ref value
  //If match found, apply matching item to skill set
}

void SkillManager::updateDataBank()
{
  DB->totalHealth = 100+(10*(healthSkill->getLevel()-1));
  DB->speed = speedSkill->getLevel();
  DB->damage = damageSkill->getLevel();
  DB->fireRate = fireRateSkill->getLevel();
  DB->shotSpeed = shotSpeedSkill->getLevel();
}

int SkillManager::getScore()
{
  return score;
}

void SkillManager::calculateScore()
{
  score = experience;
  //Send score to server with player name?
}

void SkillManager::printDataBank()
{
  cout << "DB contents:" << endl;
  cout << "totalHealth:   " << DB->totalHealth << endl;
  cout << "currentHealth: " << DB->currentHealth << endl;
  cout << "damage:        " << DB->damage << endl;
  cout << "speed:         " << DB->speed << endl;
  cout << "fireRate:      " << DB->fireRate << endl;
  cout << "shotSpeed:     " << DB->shotSpeed << endl;
}
