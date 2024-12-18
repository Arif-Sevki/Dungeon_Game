#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "enemy.h"
#include <stdio.h>


Enemy createVampire(int strength, int health);
// vampire attack implementations
int vampireAttackFirst(Enemy *enemy);
int vampireAttackSecond(Enemy *enemy);
int vampireAttackThird(Enemy *enemy);

#endif