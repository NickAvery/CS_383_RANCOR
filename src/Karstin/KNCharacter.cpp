#include "KNCharacter.h"

Character::Character(int charID, Skill *startSkills) {
  id = charID;
  startingSkills = startSkills;
}

Character::~Character() {
  
}

Skill *Character::getStartingSkills() {
  return startingSkills;
}

int Character::hasID(int charID) {
  if(id == charID) return 1;
  return 0;
}
