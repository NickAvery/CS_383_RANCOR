#include "KNCharacterDatabase.h"

CharacterDatabase::CharacterDatabase() {
  characters = (Character *)malloc(sizeof(Character) * 4);
  characters[3] = NULL;
  Skill *skillSet = (Skill *)malloc(sizeof(Skill) * 5);
  skillSet[4] = NULL;
  //CHARACTER_1 creation
  skillSet[0] = new Skill(Skill.STRENGTH, 1);
  skillSet[1] = new Skill(Skill.SPEED, 1);
  skillSet[2] = new SKill(Skill.ACCURACY, 1);
  skillSet[3] = new Skill(Skill.RESILIENCE, 1);
  characters[0] = new Character(Character.CHARACTER_1, skillSet);
  //CHARACTER_2 creation
  skillSet[0] = new Skill(Skill.STRENGTH, 1);
  skillSet[1] = new Skill(Skill.SPEED, 1);
  skillSet[2] = new SKill(Skill.ACCURACY, 1);
  skillSet[3] = new Skill(Skill.RESILIENCE, 1);
  characters[1] = new Character(Character.CHARACTER_2, skillSet);
  //CHARACTER_3 creation
  skillSet[0] = new Skill(Skill.STRENGTH, 1);
  skillSet[1] = new Skill(Skill.SPEED, 1);
  skillSet[2] = new SKill(Skill.ACCURACY, 1);
  skillSet[3] = new Skill(Skill.RESILIENCE, 1);
  characters[2] = new Character(Character.CHARACTER_3, skillSet);
  skillSet = NULL;
}

CharacterDatabase::~CharacterDatabase() {
  //None Yet
}

int CharacterDatabase::hasCharacter(int charID) {
  for (int i=0; i < 4; i++) {
    if (character[i].hasID(charID)) {
      return 1;
    }
  }
  return 0;
}

Character *CharacterDatabase::getCharacter(int charID) {
  for (int i=0; i < 4; i++) {
    if (character[i].hasID(charID)) {
      return character[i];
    }
  }
  return NULL;
}
