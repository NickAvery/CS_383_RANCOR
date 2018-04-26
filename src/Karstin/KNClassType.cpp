/* KNClassType.cpp
 * 
 * Implementation file for ClassType class. Stores a base skill preset which
 * can be selected in SkillManager to give Skills a variation based on
 * which ClassType has been selected to be played.
 * 
 * J Karstin Neill      02.21.18
 */

#include "KNClassType.h"

ClassType::ClassType(int classID, int hlth, int spd, int dmg, int fire, int shot)
{
  ID = classID;
  healthSkill    = new Skill(Skill::HEALTH, hlth);
  speedSkill     = new Skill(Skill::SPEED, spd);
  damageSkill    = new Skill(Skill::DAMAGE, dmg);
  fireRateSkill  = new Skill(Skill::FIRERATE, fire);
  shotSpeedSkill = new Skill(Skill::SHOTSPEED, shot);
}

ClassType::~ClassType()
{
  
}

//Returns skill level for skill with given skillID
int ClassType::getSkillLevel(int skillID)
{
  //Check each possible value of skillID
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
  //If skillID is invalid, return -1
  default:
    return -1;
  };
}

//Returns true if classID matches this class ID; otherwise returns false;
bool ClassType::hasID(int classID)
{
  return (ID == classID);
}
