/* KNCharacter.h
 * 
 * Interface file for Character class. Stores a base skill preset which
 * can be selected in SkillManager to give Skills a variation based on
 * which Character has been selected to be played.
 * 
 * J Karstin Neill      02.21.18
 */

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

//Necessary included headers
#include "KNSkill.h"

class Character {
 public:
  //Character ID's:
  //To be used whenever a charID field is required to reference a given character.
  //Static and constant, so should be available whenever "KNCharacter.h" is included.
  //Use: Character.CHARACTER_1 to reference "Character 1", etc.
  static const int CHARACTER_1 = 0;
  static const int CHARACTER_2 = 1;
  static const int CHARACTER_3 = 2;
  //Constructor
  //Requires a collection of starting skills given character begins with.
  Character(int charID, Skill **startSkills);
  //Destructor
  ~Character();
  //Returns collection of starting skill data assigned to this character
  Skill **getStartingSkills();
  //Returns 0 if charID is not this character, returns 1 if it is.
  int hasID(int charID);
 private:
  //Character ID
  int ID;
  //Collection of starting skills
  Skill **startingSkills;
};

#endif //CHARACTER_H
