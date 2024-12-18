#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "enemy.h"
#include <stdio.h>


Enemy createWerewolf(int strength, int health);

// werewolf attack implementations
int werewolfAttackFirst(Enemy *enemy);
int werewolfAttackSecond(Enemy *enemy);
int werewolfAttackThird(Enemy *enemy);

#endif