/* KNPermaMod.h
 * 
 * Interface file for PermaMod Item subclass.
 * This class is used for stat modifications that never leave once applied.
 * Stackable, and repeatable.
 * 
 * J Karstin Neill    4.24.18
 */

#ifndef __PERMAMOD_H__
#define __PERMAMOD_H__

#include "KNItem.h"

class PermaMod : public Item
{
 public:
  PermaMod(int *classIDs, int cIDcount, int ref, int spd, int hlth, int dmg);
  ~PermaMod();
  void apply() override;
 private:
  //Basic stat changes involved in all Items
  int speedChange;
  int healthChange;
  int damageChange;  
};

#endif //PERMAMOD_H
