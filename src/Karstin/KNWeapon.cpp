/* KNWeapon.h
 * 
 * Implementation file for Weapon Item subclass.
 * This class is used for single slot item usage, where only one is allowed at a time.
 * Any new weapon replaces the one currently equipped, which is then destroyed.
 * 
 * J Karstin Neill       4.24.18
 */

#include "KNWeapon.h"

Weapon::Weapon(int *classIDs, int cIDcount, int ref, int dmg, int *pSize, double pSpd, double pRng, double acc, int pCount, double pSprd, double pRate)
{
  validClassTypeIDs = new int[cIDcount];
  for (int i=0; i < cIDcount; i++) {
    validClassTypeIDs[i] = classIDs[i];
  }
  reference = ref;
}

Weapon::~Weapon()
{
  
}

void Weapon::apply()
{

}
