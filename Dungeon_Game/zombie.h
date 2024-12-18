#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "enemy.h"
#include <stdio.h>

Enemy createZombie(int strength, int health);
// zombie attack implementations
int zombieAttackFirst(Enemy *enemy);
int zombieAttackSecond(Enemy *enemy);
int zombieAttackThird(Enemy *enemy);


#endif