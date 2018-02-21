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

//Necessary included headers
#include "KNCharacterDatabase.h"
#include "KNSkill.h"
#include "KNScore.h"
#include "KNPowerUp.h"

class SkillManager {
  //Visible methods
 public:
  //Constructor
  SkillManager();
  //Destructor
  ~SkillManager();
  //Sets character that is being used (by character ID), and all base skill settings defined by selected character.
  //Returns: 1 if successful, 0 if charID is invalid
  //Use: int success = skillManager.selectCharacter(Character.CHARACTER_1);
  //Note: See KNCharacter.h for full list of Charater ID's
  int selectCharacter(int charID);
  //Returns the Character ID of the currently selected character
  //Returns -1 if no character is currently selected
  int getSelectedCharacter();
  //Returns current level of skill with given Skill ID
  //Returns -1 if skillID is invalid
  //Use: int speedLevel = skillManager.getSkillLevel(Skill.SPEED);
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
  Skill skills[];
  //Reference to CharacterDatabase object
  CharacterDatabase *characterDatabase;
  //Reference to currently selected Character
  Character *selectedCharacter;
  //Collection of active PowerUps
  PowerUp *appliedPowerUps;
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
