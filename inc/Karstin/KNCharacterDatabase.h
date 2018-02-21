#ifndef __CHARACTERDATABASE_H__
#define __CHARACTERDATABASE_H__

#include "KNCharacter.h"

class CharacterDatabase {
 public:
  CharacterDatabase();
  ~CharacterDatabase();
  int hasCharacter(int charID);
  Character *getCharacter(int charID);
 private:
  Character **characters;
};

#endif //CHARACTERDATABASE_H
