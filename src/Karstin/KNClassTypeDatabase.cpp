#include "KNClassTypeDatabase.h"
#include <iostream>

ClassTypeDatabase::ClassTypeDatabase() {
  classTypes = new ClassType*[3];
  //WARRIOR creation
  classTypes[0] = new ClassType(ClassType::WARRIOR, 3, 1, 2, 3, 5);
  //RANGER creation
  classTypes[1] = new ClassType(ClassType::RANGER, 3, 1, 2, 3, 5);
  //DR_BC creation
  classTypes[2] = new ClassType(ClassType::DR_BC, 3, 1, 2, 3, 5);
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
