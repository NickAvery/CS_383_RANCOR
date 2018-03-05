#include "KNClassType.h"

ClassType::ClassType(int classID, int hlth, int spd, int dmg, int fire, int shot) {
  ID = classID;
  healthSkill    = new Skill(Skill::HEALTH, hlth);
  speedSkill     = new Skill(Skill::SPEED, spd);
  damageSkill    = new Skill(Skill::DAMAGE, dmg);
  fireRateSkill  = new Skill(Skill::FIRERATE, fire);
  shotSpeedSkill = new Skill(Skill::SHOTSPEED, shot);
}

ClassType::~ClassType() {
  
}

int ClassType::getSkillLevel(int skillID) {
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

int ClassType::hasID(int classID) {
  if(ID == classID) return 1;
  return 0;
}
