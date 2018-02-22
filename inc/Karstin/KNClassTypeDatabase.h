#ifndef __CLASSTYPEDATABASE_H__
#define __CLASSTYPEDATABASE_H__

#include "KNClassType.h"

class ClassTypeDatabase {
 public:
  ClassTypeDatabase();
  ~ClassTypeDatabase();
  int hasClassType(int classID);
  ClassType *getClassType(int classID);
 private:
  ClassType **classTypes;
};

#endif //CLASSTYPEDATABASE_H
