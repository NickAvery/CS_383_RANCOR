#include "KNCharacterDatabase.h"

CharacterDatabase::CharacterDatabase() {
  characters = new Character*[4];
  characters[3] = NULL;
  Skill **skillSet = new Skill*[5];
  skillSet[4] = NULL;
  //CHARACTER_1 creation
  skillSet[0] = new Skill(Skill.STRENGTH, 3);
  skillSet[1] = new Skill(Skill.SPEED, 1);
  skillSet[2] = new SKill(Skill.ACCURACY, 2);
  skillSet[3] = new Skill(Skill.RESILIENCE, 3);
  characters[0] = new Character(Character.WARRIOR, skillSet);
  //CHARACTER_2 creation
  skillSet[0] = new Skill(Skill.STRENGTH, 1);
  skillSet[1] = new Skill(Skill.SPEED, 3);
  skillSet[2] = new SKill(Skill.ACCURACY, 3);
  skillSet[3] = new Skill(Skill.RESILIENCE, 2);
  characters[1] = new Character(Character.RANGER, skillSet);
  //CHARACTER_3 creation
  skillSet[0] = new Skill(Skill.STRENGTH, 3);
  skillSet[1] = new Skill(Skill.SPEED, 3);
  skillSet[2] = new SKill(Skill.ACCURACY, 3);
  skillSet[3] = new Skill(Skill.RESILIENCE, 4);
  characters[2] = new Character(Character.DR_BC, skillSet);
  skillSet = NULL;
}

CharacterDatabase::~CharacterDatabase() {
  //None Yet
}

int CharacterDatabase::hasCharacter(int charID) {
  for (int i=0; i < 4; i++) {
    if (character[i]->hasID(charID)) {
      return 1;
    }
  }
  return 0;
}

Character *CharacterDatabase::getCharacter(int charID) {
  for (int i=0; i < 4; i++) {
    if (character[i]->hasID(charID)) {
      return character[i];
    }
  }
  return NULL;
}
