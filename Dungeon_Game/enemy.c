#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "goblin.h"
#include "zombie.h"
#include "orc.h"
#include "werewolf.h"
#include "giantBear.h"
#include "skeletonSoldier.h"
#include "ghost.h"
#include "vampire.h"
#include "spiderQuenn.h"
#include "finalboss.h"


// General function to create enemies
Enemy createEnemy(const char *name, int health, int strength, 
                  int (*attack1)(Enemy *),
                  int (*attack2)(Enemy *),
                  int (*attack3)(Enemy *)) {
    Enemy enemy;
    enemy.name = strdup(name);
    enemy.maxHealth = health;
    enemy.currentHealth = health;
    enemy.strength = strength;

    enemy.attackFirst = attack1;
    enemy.attackSecond = attack2;
    enemy.attackThird = attack3;
    return enemy;
}

// Function to free allocated memory for an Enemy
void freeEnemy(Enemy *enemy) {
    if (enemy->name) {
        free(enemy->name);
        enemy->name = NULL;
    }
}

// Handle damage
void takeDamageEnemy(Enemy *enemy, int damage) {
    enemy->currentHealth -= damage;
    if (enemy->currentHealth < 0) enemy->currentHealth = 0;
    printf("%s takes %d damage. Current health: %d\n", enemy->name, damage, enemy->currentHealth);
}

// Generalized attack handling
int attackEnemy(Enemy *enemy, int roll) {
    switch (roll) {
        case 1: case 2: case 3:
            return enemy->attackFirst(enemy);
        case 4: case 5:
            return enemy->attackSecond(enemy);
        case 6:
            return enemy->attackThird(enemy);
        default:
            printf("Invalid roll.\n");
            return 0;
    }
}

Enemy createBoss(int strength, int health) {
    return createEnemy("Devil of All Sins", health, strength, bossAttackFirst, bossAttackSecond, bossAttackThird);
}



// Boss-specific attack implementations
int bossAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 3;
    printf("Demon sends hellfire at you, dealing %d damage.\n", damage);
    return damage;
}

int bossAttackSecond(Enemy *enemy) {
    printf("Demon heals itself.\n");
    enemy->currentHealth += 50;
    if (enemy->currentHealth > enemy->maxHealth) {
        enemy->currentHealth = enemy->maxHealth;
    }
    return 0;
}

int bossAttackThird(Enemy *enemy) {
    enemy->strength += 5;
    printf("Demon calls hell to earth, gaining 5 strength.\n");
    return 0;
}

Enemy createBear(int strength, int health) {
    return createEnemy("Giant Bear", health, strength, bearAttackFirst, bearAttackSecond, bearAttackThird);
}


// bear-specific attack implementations
int bearAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 2;
    printf("Giant Bear claws you, dealing %d damage.\n", damage); 
    return damage;
}

int bearAttackSecond(Enemy *enemy) {
    int damage = enemy->strength + 10;
    printf("Giant Bear bites you, dealing %d damage.\n", damage); 
    return damage;
}

int bearAttackThird(Enemy *enemy) {
    int damage = enemy->strength * 4;
    printf("The Giant Bear attacks with all its might, dealing %d damage.\n", damage); 
    return damage;
}

Enemy createGhost(int strength, int health) {
    return createEnemy("Ghost", health, strength, ghostAttackFirst, ghostAttackSecond, ghostAttackThird);
}



// ghost-specific attack implementations
int ghostAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 2;
    printf("Ghost eats your soul, dealing %d damage.\n", damage); 
    return damage;
}

int ghostAttackSecond(Enemy *enemy) {
    printf("Ghost heals itself.\n");
    enemy->currentHealth += 10;
    return 0;
}

int ghostAttackThird(Enemy *enemy) {
    int damage = enemy->strength * 4;
    printf("The ghost blows freezing cold on you, dealing %d damage.\n", damage); 
    return damage;
}


// Function to create a goblin enemy
Enemy createGoblin(int strength, int health) {
    return createEnemy("Goblin", health, strength, goblinAttackFirst, goblinAttackSecond, goblinAttackThird);
}



// Goblin-specific attack implementations
int goblinAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 2;
    printf("Goblin throws a stone, dealing %d damage.\n", damage);
    return damage;
}

int goblinAttackSecond(Enemy *enemy) {
    printf("Goblin is preparing but does nothing this turn.\n");
    return 0;
}

int goblinAttackThird(Enemy *enemy) {
    int damage = enemy->strength * 5;
    printf("Goblin uses Dagger Strike, dealing %d damage.\n", damage);
    return damage;
}

Enemy createOrc(int strength, int health) {
    return createEnemy("Orc", health, strength, orcAttackFirst, orcAttackSecond, orcAttackThird);
}


// Orc-specific attack implementations 
int orcAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 2;
    printf("Orc hits you with a club, dealing %d damage.\n", damage); 
    return damage;
}

int orcAttackSecond(Enemy *enemy) {
    printf("Orc getting angry. His power increasing.\n");
    enemy->strength += 2;
    return 0;
}

int orcAttackThird(Enemy *enemy) {
    int damage = enemy->strength * 4;
    printf("Orc Smash, dealing %d damage.\n", damage); 
    return damage;
}

Enemy createSkeletonSoldier(int strength, int health) {
    return createEnemy("Skeleton Soldier", health, strength, skeletonSoldierAttackFirst, skeletonSoldierAttackSecond, skeletonSoldierAttackThird);
}



// Boss-specific attack implementations
int skeletonSoldierAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 2;
    printf("Skeleton Soldier shoot an arrow, dealing %d damage.\n", damage); 
    return damage;
}

int skeletonSoldierAttackSecond(Enemy *enemy) {
    printf("Skeleton Soldier shoot an arrow. It is a miss.\n");
    return 0;
}

int skeletonSoldierAttackThird(Enemy *enemy) {
    int damage = enemy->strength * 4;
    printf("Skeleton Soldier bites you, dealing %d damage.\n", damage); 
    return 0;
}

Enemy createSpiderQuenn(int strength, int health) {
    return createEnemy("Spider Quenn", health, strength, spiderQuennAttackFirst, spiderQuennAttackSecond, spiderQuennAttackThird);
}


// Spider Quenn-specific attack implementations
int spiderQuennAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 2;
    printf("Spider Quenn send her children to attack you, dealing %d damage.\n", damage); 
    return damage;
}

int spiderQuennAttackSecond(Enemy *enemy) {
    printf("Spider Quenn eat her eggs. Gaining 5 str \n");
    enemy->strength += 5;
    return 0;
}

int spiderQuennAttackThird(Enemy *enemy) {
    int damage = enemy->strength + 15;
    printf("Spider Quinn throws acidic web, dealing %d damage.\n", damage); 
    return 0;
}

Enemy createVampire(int strength, int health) {
    return createEnemy("Vampire", health, strength, vampireAttackFirst, vampireAttackSecond, vampireAttackThird);
}


// vampire-specific attack implementations
int vampireAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 3;
    printf("Vampire shoots blood spears, dealing %d damage.\n", damage); 
    return damage;
}

int vampireAttackSecond(Enemy *enemy) {
    printf("Vampire drinks your blood. dealing %d damage.\n", 10);
    printf("Vampire heals itself.\n");
    enemy->currentHealth += 10;
    return 10;
}

int vampireAttackThird(Enemy *enemy) {
    int damage = enemy->strength * 4;
    printf("The Vampire use Blood Hell attack, dealing %d damage.\n", damage); 
    return damage;
}


Enemy createWerewolf(int strength, int health) {
    return createEnemy("Werewolf", health, strength, werewolfAttackFirst, werewolfAttackSecond, werewolfAttackThird);
}



// werewolf-specific attack implementations
int werewolfAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 3;
    printf("Werewolf use his claws to attack, dealing %d damage.\n", damage); 
    return damage;
}

int werewolfAttackSecond(Enemy *enemy) {
    int damage = enemy->strength * 4;
    printf("Werewolf use Burning Bite , dealing %d damage.\n", damage); 
    return damage;
}

int werewolfAttackThird(Enemy *enemy) {
    int damage = enemy->strength * 5;
    printf("The werewolf shoots fire tooths, dealing %d damage.\n", damage); 
    return damage;
}

Enemy createZombie(int strength, int health) {
    return createEnemy("Zombie", health, strength, zombieAttackFirst, zombieAttackSecond, zombieAttackThird);
}


// zombie-specific attack implementations
int zombieAttackFirst(Enemy *enemy) {
    int damage = enemy->strength * 2;
    printf("Zombie bites you, dealing %d damage.\n", damage); 
    return damage;
}

int zombieAttackSecond(Enemy *enemy) {
    printf("Zombie falls to the ground.\n");
    return 0;
}

int zombieAttackThird(Enemy *enemy) {
    int damage = enemy->strength * 4;
    printf("Zombie bites you arm, dealing %d damage.\n", damage); 
    return damage;
}