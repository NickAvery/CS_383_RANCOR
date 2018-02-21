#include "KNCharacter.h"

Character::Character(int charID, Skill **startSkills) {
  id = charID;
  startingSkills = new Skill*[5];
  startingSkills[4] = NULL;
  for (int i=0; i < 4; i++) {
    startingSkills[i] = startSkills[i];
  }
}

Character::~Character() {
  
}

Skill **Character::getStartingSkills() {
  return startingSkills;
}

int Character::hasID(int charID) {
  if(id == charID) return 1;
  return 0;
}
