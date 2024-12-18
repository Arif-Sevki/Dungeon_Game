#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"
#include "item.h"
#include "dungeon.h" 

// Player Struct
typedef struct {
    int maxHealth; 
    int currentHealth;
    int strength; 
    Inventory inventory; 
    Room *currentRoom; 
} Player;

// Function prototypes
Player createPlayer(int hp, int atk);
 
int earthquakeStomp();
int shadowPiercer();
int infernoBurst();
int healingAura();
int lightningStrike();
int divineSlash();

void fullRecovered();
void increaseMaxHealth(int amount);
void increaseHealth(int amount);
void increaseAttackPower(int amount);

int getMaxHealth();
int getHealth();
int getAttackPower();

void takeDamagePlayer(int damage);
int attack(int roll);

#endif // PLAYER_H