#ifndef GHOST_H
#define GHOST_H

#include "enemy.h"


// ghost attack implementations
int ghostAttackFirst(Enemy *enemy);
int ghostAttackSecond(Enemy *enemy);
int ghostAttackThird(Enemy *enemy);


Enemy createGhost(int strength, int health);
#endif