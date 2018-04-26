/* KNItem.h
 * 
 * Interface file of Item class. Used as a super class for inherited specific item types.
 * 
 * J Karstin Neill       4.24.18
 */

#ifndef __ITEM_H__
#define __ITEM_H__

class Item
{
 public:
  Item();
  Item(int *classIDs, int cIDcount, int ref);
  ~Item();
  virtual void apply() = 0;
  bool hasReference(int ref);
 protected:
  //Types of class IDs that can use this item
  int *validClassTypeIDs;
  int reference;
  //Map image
  //Pixmap image;
};

#endif //ITEM_H
