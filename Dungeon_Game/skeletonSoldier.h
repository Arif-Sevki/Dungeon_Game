#ifndef SKELETONSOLDIER_H
#define SKELETONSOLDIER_H

#include "enemy.h"
#include <stdio.h>

Enemy createSkeletonSoldier(int strength, int health);

//skeletonSoldier attack implementations
int skeletonSoldierAttackFirst(Enemy *enemy);
int skeletonSoldierAttackSecond(Enemy *enemy);
int skeletonSoldierAttackThird(Enemy *enemy);
#endif