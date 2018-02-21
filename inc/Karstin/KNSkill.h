/* KNSkill.h
 * 
 * Interface file for Skill class. Skills are used externally to provide a
 * more dynamic experience-based world interaction. SkillManager uses a collection
 * of skills to do this, where it store experience and level them up as needed.
 * Skills themselves are merely a storage unit for the level of a given stat.
 * They are each defined and referenced by a unique Skill ID, as explained below.
 * 
 * J Karstin Neill       02.21.18
 */

#ifndef __SKILL_H__
#define __SKILL_H__

class Skill {
 public:
  //Skill ID's:
  //To be used whenever a skillID field is required to reference a given skill.
  //Static and constant, so should be available whenever "KNSkill.h" is included.
  //Use: Skill.SPEED to reference "speed", etc.
  static const int STRENGTH = 0;
  static const int SPEED = 1;
  static const int ACCURACY = 2;
  static const int RESILIENCE = 3;
  //Constructor
  //Requires a Skill ID
  Skill(int skillID);
  //Constructor with starting point set at startingLevel
  Skill(int skillID, int startingLevel);
  //Destructor
  ~Skill();
  //Returns 0 if this skill does not have given ID; returns 1 if it does
  int hasID(int skillID);
  //Returns current level of this skill
  int getLevel();
  //Adds amount on to current skill level. If level goes below 0, floor at 0.
  void levelUp(int amount);
  //Sets current skill level to given value. Floor at 0.
  void setLevel(int value);
 private:
  //Current skill level
  int level;
  //Skill ID
  int ID;
};

#endif //SKILL_H
