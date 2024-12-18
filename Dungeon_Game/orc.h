#ifndef ORC_H
#define ORC_H

#include "enemy.h"

// Orc attack implementations
int orcAttackFirst(Enemy *enemy);
int orcAttackSecond(Enemy *enemy);
int orcAttackThird(Enemy *enemy);


Enemy createOrc(int strength, int health);


#endif  // ORC_H