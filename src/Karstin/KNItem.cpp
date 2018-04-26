/* KNItem.cpp
 *
 * Implementation file for Item class.
 *
 * J Karstin Neill     4.24.18
 */

#include "KNItem.h"

Item::Item()
{

}

Item::Item(int *classIDs, int cIDcount, int ref)
{
  validClassTypeIDs = new int[cIDcount];
  for (int i=0; i < cIDcount; i++) {
    validClassTypeIDs[i] = classIDs[i];
  }
  reference = ref;
}

Item::~Item()
{
  
}

bool Item::hasReference(int ref)
{
  return (reference == ref);
}
