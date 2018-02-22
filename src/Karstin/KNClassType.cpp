#include "KNClassType.h"

ClassType::ClassType(int classID, Skill **startSkills) {
  id = classID;
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
  if(id == classID) return 1;
  return 0;
}
