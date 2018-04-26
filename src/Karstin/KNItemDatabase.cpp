/* KNItemDatabase.cpp
 * 
 * Implementation file for ItemDatabase class.
 * 
 * J Karstin Neill     4.24.18
 */

#include "KNItemDatabase.h"

ItemDatabase::ItemDatabase()
{
  //Create and initialize the saved items
  items = new Item*[6];

  items[0] = new Weapon();
  items[1] = new Weapon();
  items[2] = new Weapon();
  items[3] = new PermaMod();
  items[4] = new PermaMod();
  items[5] = new PermaMod();
}

Item *ItemDatabase::getItem(int ref)
{
  for (int i=0; i < 6; i++)
  {
    if (items[i].hasReference(ref)) return items[i];
  }
  return NULL;
}

ItemDatabase::~ItemDatabase()
{
  
}

bool ItemDatabase::hasItem(int ref)
{
  for (int i=0; i < 6; i++)
  {
    if (items[i].hasReference(ref)) return true;
  }
  return false;
}
