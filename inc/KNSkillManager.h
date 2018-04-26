/* KNSkillManager.h
 * 
 * Interface file for SkillManager class. Used as a central access point to all
 * Skill information, as well as character selection. Handles experience adding,
 * level ups, and PowerUp application/timing.
 * 
 * J Karstin Neill       02.21.18
 */

#ifndef __SKILLMANAGER_H__
#define __SKILLMANAGER_H__

#include "BTcharacter.h"
class Character;

//Necessary included headers
#include "KNClassTypeDatabase.h"
#include "KNSkill.h"
#include "KNItemDatabase.h"
#include "KNItem.h"
#include "KNWeapon.h"
#include "KNPermaMod.h"

struct DataBank {
  int size[2];
  int totalHealth;
  int currentHealth;
  int speed;
  int damage;
  int fireRate;
  int shotSpeed;
};

struct ItemData {
  int reference;
  //Pixmap image;
};

class SkillManager {
  //Visible methods
 public:
  //Constructor
  //Use Class Type ID in place of classID; example: ClassType::WARRIOR
  SkillManager(Character *parent = 0, int classID = 0);
  //Destructor
  ~SkillManager();
  //Sets class type that is being used (by Class Type ID), and all base skill settings defined by selected class type.
  //Returns: true if successful, false if classID is invalid
  //Use: bool success = skillManager.selectClassType(ClassType::WARRIOR);
  //Note: See KNClassType.h for full list of Class Type ID's
  bool selectClassType(int classID);
  //Returns current level of skill with given Skill ID
  //Returns -1 if skillID is invalid
  //Use: int speedLevel = skillManager.getSkillLevel(Skill::SPEED);
  //Note: See KNSkill.h for full list of Skill ID's
  int getSkillLevel(int skillID);
  //Returns value of current level (1 + number of level ups applied)
  int getLevel();
  //Adds experience to the Skills, applies level ups when necessary
  void addExperience(int amount);

  //Looks for item with matching ref value, and applies item stat changes to skill data
  bool addItem(int ref);

  //Ported over from Score class
  //Return the current score value
  int getScore();
  //Calculate the current score based on experience value
  void calculateScore();

 private:
  struct DataBank *DB;
  //Collection of skills
  Skill *healthSkill;
  Skill *speedSkill;
  Skill *damageSkill;
  Skill *fireRateSkill;
  Skill *shotSpeedSkill;
  //Reference to ClassTypeDatabase object
  ClassTypeDatabase *classTypeDatabase;
  //Reference to currently selected ClassType
  ClassType *selectedClassType;

  //Collection of collected Items
  Item **collectedItems;
  //ItemDatabase
  ItemDatabase *itemDatabase;

  //Total skill level
  int totalLevel;
  //Current experience collected
  int experience;
  //Amount of total experience which will give next level up
  int nextLevelExperience;
  //Rate at which nextLevelExperience increases for next level
  double growthMultiplier;
  //Player score variable
  int score;
  //Update DB to current values
  void updateDataBank();
  //Display current DB values
  void printDataBank();
  //Level up skills by given level amount
  void levelUp(int levels);
};

#endif //SKILLMANAGER_H
