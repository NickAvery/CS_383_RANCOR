/* KNItemDatabase.h
 * 
 * Interface file for ItemDatabase class.
 * 
 * J Karstin Neill     4.24.18
 */

#ifndef __ITEMDATABASE_H__
#define __ITEMDATABASE_H__

class ItemDatabase {
 public:
  ItemDatabase();
  ~ItemDatabase();
  bool hasItem(int ref);
  Item *getItem(int ref);
 private:

  Item **items;
  /*
  //Weapons
  Item *shotgun;
  Item *machine;
  Item *pistol;
  //PermaMods
  Item *speedBoost;
  Item *damageBoost;
  Item *healthBoost;
  */
};

#endif //ITEMDATABASE_H
