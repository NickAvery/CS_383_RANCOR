/* KNWeapon.h
 * 
 * Interface file for Weapon Item subclass.
 * This class is used for single slot item usage, where only one is allowed at a time.
 * Any new weapon replaces the one currently equipped, which is then destroyed.
 * 
 * J Karstin Neill       4.24.18
 */

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "KNItem.h"

class Weapon : public Item
{
 public:
  //Constructor
  Weapon(int *classIDs, int cIDcount, int ref, int dmg, int *pSize, double pSpd, double pRng, double acc, int pCount, double pSprd, double pRate);
  //Destructor
  ~Weapon();
  override void apply();
 private:
  //Stat changes to projectiles
  int *projSize;
  double projSpeed;
  double projRange;
  double accuracy;
  int numOfProj;
  double projSpread;
  double projFireRate;
};

#endif //WEAPON_H
