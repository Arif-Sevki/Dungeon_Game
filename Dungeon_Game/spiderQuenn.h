#ifndef SPIDERQUENN_H
#define SPIDERQUENN_H

#include "enemy.h"


Enemy createSpiderQuenn(int strength, int health);
// Spider Quenn  attack implementations
int spiderQuennAttackFirst(Enemy *enemy);
int spiderQuennAttackSecond(Enemy *enemy);
int spiderQuennAttackThird(Enemy *enemy);

#endif