#ifndef GIANTBEAR_H
#define GIANTBEAR_H

#include "enemy.h"


// bear attack implementations
int bearAttackFirst(Enemy *enemy);
int bearAttackSecond(Enemy *enemy);
int bearAttackThird(Enemy *enemy);


Enemy createBear(int strength, int health);

#endif