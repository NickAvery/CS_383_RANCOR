/* KNClassType.h
 * 
 * Interface file for ClassType class. Stores a base skill preset which
 * can be selected in SkillManager to give Skills a variation based on
 * which ClassType has been selected to be played.
 * 
 * J Karstin Neill      02.21.18
 */

#ifndef __CLASSTYPE_H__
#define __CLASSTYPE_H__

//Necessary included headers
#include "KNSkill.h"

class ClassType
{
 public:
  //Class Type ID's:
  //To be used whenever a classID field is required to reference a given class type.
  //Static and constant, so should be available whenever "KNClassType.h" is included.
  //Use: ClassType::WARRIOR to reference the Warrior class type, etc.
  static const int WARRIOR = 0;
  static const int RANGER  = 1;
  static const int DR_BC   = 2;
  //Constructor
  //Requires a collection of starting skills given class type begins with.
  ClassType(int classID, int hlth, int spd, int dmg, int fire, int shot);
  //Destructor
  ~ClassType();
  //Returns level of skill with given Skill ID assigned to this class type
  int getSkillLevel(int skillID);
  //Returns 0 if classID is not this class type, returns 1 if it is.
  bool hasID(int classID);
 private:
  //Class Type ID
  int ID;
  //Collection of starting skills
  Skill *healthSkill;
  Skill *speedSkill;
  Skill *damageSkill;
  Skill *fireRateSkill;
  Skill *shotSpeedSkill;
};

#endif //CLASSTYPE_H
