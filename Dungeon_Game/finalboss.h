#ifndef FINALBOSS_H
#define FINALBOSS_H

#include "enemy.h"

Enemy createBoss(int strength, int health);

// Boss attack implementations
int bossAttackFirst(Enemy *enemy);
int bossAttackSecond(Enemy *enemy);
int bossAttackThird(Enemy *enemy);

#endif // GOBLIN_H

