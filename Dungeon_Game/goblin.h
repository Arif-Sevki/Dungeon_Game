#ifndef GOBLIN_H
#define GOBLIN_H

#include "enemy.h"

// Declare goblin attack functions
int goblinAttackFirst(Enemy *enemy);
int goblinAttackSecond(Enemy *enemy);
int goblinAttackThird(Enemy *enemy);

// Declare the goblin creation function
Enemy createGoblin(int strength, int health);

#endif // GOBLIN_H