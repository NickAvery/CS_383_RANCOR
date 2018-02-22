#include "KNClassTypeDatabase.h"
#include <iostream>

ClassTypeDatabase::ClassTypeDatabase() {
  classTypes = new ClassType*[4];
  classTypes[3] = NULL;
  Skill **skillSet = new Skill*[5];
  skillSet[4] = NULL;
  //WARRIOR creation
  skillSet[0] = new Skill(Skill::STRENGTH, 3);
  skillSet[1] = new Skill(Skill::SPEED, 1);
  skillSet[2] = new Skill(Skill::ACCURACY, 2);
  skillSet[3] = new Skill(Skill::RESILIENCE, 3);
  classTypes[0] = new ClassType(ClassType::WARRIOR, skillSet);
  //RANGER creation
  skillSet[0] = new Skill(Skill::STRENGTH, 1);
  skillSet[1] = new Skill(Skill::SPEED, 3);
  skillSet[2] = new Skill(Skill::ACCURACY, 3);
  skillSet[3] = new Skill(Skill::RESILIENCE, 2);
  classTypes[1] = new ClassType(ClassType::RANGER, skillSet);
  //DR_BC creation
  skillSet[0] = new Skill(Skill::STRENGTH, 3);
  skillSet[1] = new Skill(Skill::SPEED, 3);
  skillSet[2] = new Skill(Skill::ACCURACY, 3);
  skillSet[3] = new Skill(Skill::RESILIENCE, 4);
  classTypes[2] = new ClassType(ClassType::DR_BC, skillSet);
}

ClassTypeDatabase::~ClassTypeDatabase() {
  //None Yet
}

int ClassTypeDatabase::hasClassType(int classID) {
  for (int i=0; i < 4; i++) {
    if (classTypes[i]->hasID(classID)) {
      return 1;
    }
  }
  return 0;
}

ClassType *ClassTypeDatabase::getClassType(int classID) {
  for (int i=0; i < 4; i++) {
    if (classTypes[i]->hasID(classID)) {
      return classTypes[i];
    }
  }
  return NULL;
}
