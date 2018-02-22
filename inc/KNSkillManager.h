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

//Necessary included headers
#include "KNClassTypeDatabase.h"
#include "KNSkill.h"
#include "KNScore.h"
#include "KNPowerUp.h"
class Character;
class SkillManager {
  //Visible methods
 public:
  //Constructor
  //Use Class Type ID in place of classID; example: ClassType::WARRIOR
  SkillManager(Character *parent = 0, int classID = 0);
  //Destructor
  ~SkillManager();
  //Sets class type that is being used (by Class Type ID), and all base skill settings defined by selected class type.
  //Returns: 1 if successful, 0 if classID is invalid
  //Use: int success = skillManager.selectClassType(ClassType::WARRIOR);
  //Note: See KNClassType.h for full list of Class Type ID's
  int selectClassType(int classID);
  //Returns the Class Type ID of the currently selected class type
  //Returns -1 if no class type is currently selected
  int getSelectedClassTypeID();
  //Returns current level of skill with given Skill ID
  //Returns -1 if skillID is invalid
  //Use: int speedLevel = skillManager.getSkillLevel(Skill::SPEED);
  //Note: See KNSkill.h for full list of Skill ID's
  int getSkillLevel(int skillID);
  //Returns value total Skill level
  int getTotalLevel();
  //Adds experience to the Skills, applies level ups when necessary
  void addExperience(int amount);
  //Stores and applies given PowerUp
  void applyPowerUp(PowerUp *p);
  //Tick down all PowerUp timers; destroys and removes PowerUps which have been depleted
  void tickDownPowerUps(double seconds);
 private:
  //Collection of skills
  Skill **skills;
  //Reference to ClassTypeDatabase object
  ClassType *classTypeDatabase;
  //Reference to currently selected ClassType
  ClassType *selectedClassType;
  //Collection of active PowerUps
  PowerUp **appliedPowerUps;
  //Reference to Score object
  Score *score;
  //Total skill level
  int totalLevel;
  //Current experience collected
  int experience;
  //Amount of total experience which will give next level up
  int nextLevelExperience;
};

#endif //SKILLMANAGER_H
