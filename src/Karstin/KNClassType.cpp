#include "KNClassType.h"
#include <iostream>

ClassType::ClassType(int classID, Skill **startSkills) {
  ID = classID;
  startingSkills = new Skill*[5];
  startingSkills[4] = NULL;
  for (int i=0; i < 4; i++) {
    startingSkills[i] = startSkills[i];
  }
}

ClassType::~ClassType() {
  
}

Skill **ClassType::getStartingSkills() {
  return startingSkills;
}

int ClassType::hasID(int classID) {
  if(ID == classID) return 1;
  return 0;
}
