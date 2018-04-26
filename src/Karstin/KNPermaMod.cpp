/* KNPermaMod.h
 * 
 * Implementation file for PermaMod Item subclass.
 * This class is used for stat modifications that never leave once applied.
 * Stackable, and repeatable.
 * 
 * J Karstin Neill    4.24.18
 */

#include "KNPermaMod.h"

PermaMod::PermaMod(int *classIDs, int cIDcount, int ref, int spd, int hlth, int dmg)
{
  validClassTypeIDs = new int[cIDcount];
  for (int i=0; i < cIDcount; i++)
  {
    validClassTypeIDs[i] = classIDs[i];
  }
  reference = ref;
}

PermaMod::~PermaMod()
{
  
}

void PermaMod::apply()
{
  
}
