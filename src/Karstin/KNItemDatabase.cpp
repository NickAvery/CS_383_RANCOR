/* KNItemDatabase.cpp
 * 
 * Implementation file for ItemDatabase class.
 * 
 * J Karstin Neill     4.24.18
 */

#include "KNItemDatabase.h"

#include <iostream>

ItemDatabase::ItemDatabase()
{
  //Create and initialize the saved items
  items = new Item*[6];

  int allClasses[] = {0, 1, 2};
  int projSize[] = {10, 30};

  items[0] = new Weapon(allClasses, 3, 0, 3, projSize, 3, 100, 0.2, 4, 12, 0.1);
  items[1] = new Weapon(allClasses, 3, 1, 3, projSize, 3, 100, 0.2, 4, 12, 0.1);
  items[2] = new Weapon(allClasses, 3, 2, 3, projSize, 3, 100, 0.2, 4, 12, 0.1);
  items[3] = new PermaMod(allClasses, 3, 3, 3, 0, 0);
  items[4] = new PermaMod(allClasses, 3, 4, 0, 3, 0);
  items[5] = new PermaMod(allClasses, 3, 5, 0, 0, 3);
}

Item *ItemDatabase::getItem(int ref)
{
  for (int i=0; i < 6; i++)
  {
    if (items[i]->hasReference(ref)) return items[i];
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
    if (items[i]->hasReference(ref)) return true;
  }
  return false;
}
