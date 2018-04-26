/* KNSkill.cpp
 * 
 * Implementation file for Skill class.
 * 
 * J Karstin Neill     4.24.18
 */

#include "KNSkill.h"

//Constructor (basic)
Skill::Skill(int skillID)
{
  ID = skillID;
  level = 0;
  mod = 0;
}

//Constructor (with starting level value given)
Skill::Skill(int skillID, int startingLevel)
{
  ID = skillID;
  level = startingLevel;
  mod = 0;
}

//Destructor
Skill::~Skill()
{
  
}

bool Skill::hasID(int skillID)
{
  return (ID == skillID);
}

int Skill::getLevel()
{
  return level + mod;
}

void Skill::levelUp(int amount)
{
  mod += amount;
  if (level + mod < 0) mod = -level;
}

void Skill::setLevel(int value)
{
  level = value;
  if (level + mod < 0) mod = -level;
}
