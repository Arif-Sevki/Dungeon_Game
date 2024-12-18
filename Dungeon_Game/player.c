#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// Define the Player object globally
static Player player;

Player createPlayer(int hp, int atk) {
    player.maxHealth = hp;
    player.currentHealth = hp;
    player.strength = atk;

    // Initialize inventory
    initializeInventory(&player.inventory); // Ensure this function is defined in item.c

    // Set the player's starting room (assuming dungeon is initialized elsewhere)
    player.currentRoom = dungeon[0]; // Set the player's starting room

    return player; // Optional: Return the global player for convenience
}

// Ability implementations 
int earthquakeStomp() {
    printf("You used Earthquake Stomp.");
    printf("With a single stomp, you shatter the ground,");
    printf("sending shockwaves that stagger all enemies within reach.");
    int damage = player.strength;
    printf("You dealt %d damage.", damage);
    return damage;
}

int shadowPiercer() {
    printf("You used Shadow Piercer.");
    printf("In a swift, shadowy strike, you pierce through the enemy's defenses,");
    printf("exploiting their weakest point.");
    int damage = player.strength + 20;
    printf("You dealt %d damage.", damage);
    return damage;
}

int infernoBurst() {
    printf("You used Inferno Burst.");
    printf("Unleashing flames from within, you engulf the battlefield in a fiery blaze.");
    int damage = player.strength * 3;
    printf("You dealt %d damage.", damage);
    return damage;
}

int healingAura() {
    printf("You used Healing Aura.");
    printf("A gentle glow surrounds you, restoring life and strength.");
    int amount = 50;
    if (player.currentHealth + amount > player.maxHealth) {
        player.currentHealth = player.maxHealth;
    } else {
        player.currentHealth += amount;
    }
    printf("You healed %d HP. Total health: %d", amount, player.currentHealth);
    return 0;
}

int lightningStrike() {
    printf("You used Lightning Strike.");
    printf("Calling upon the fury of storms, a bolt of lightning strikes with blinding speed.");
    int damage = player.strength * 4;
    printf("You dealt %d damage.", damage);
    return damage;
}

int divineSlash() {
    printf("You used Divine Slash.");
    printf("With a gleaming blade, you deliver a divine strike, vanquishing evil.");
    int damage = player.strength * 5 + 50;
    printf("You dealt %d damage.", damage);
    return damage;
}

// Player health management functions
void fullRecovered() {
    player.currentHealth = player.maxHealth;
}

void increaseMaxHealth(int amount) {
    player.maxHealth += amount;
    player.currentHealth = player.maxHealth; // Fully heal after max health increase
}

void increaseHealth(int amount) {
    player.currentHealth += amount;
    if (player.currentHealth > player.maxHealth) {
        player.currentHealth = player.maxHealth;
    }
}

void increaseAttackPower(int amount) {
    player.strength += amount;
}

// Getters for player stats
int getMaxHealth() {
    return player.maxHealth;
}

int getHealth() {
    return player.currentHealth;
}

int getAttackPower() {
    return player.strength;
}

// Damage and attack functions
void takeDamagePlayer(int damage) {
    printf("Player takes %d damage.\n", damage);
    printf("Health before damage: %d\n", player.currentHealth);
    player.currentHealth -= damage;
    if (player.currentHealth < 0) {
        player.currentHealth = 0;
    }
    printf("Health after damage: %d\n", player.currentHealth);
}

int attack(int roll) {
    switch (roll) {
        case 1: return earthquakeStomp();
        case 2: return shadowPiercer();
        case 3: return infernoBurst();
        case 4: return healingAura();
        case 5: return lightningStrike();
        case 6: return divineSlash();
        default: return 0;
    }
}

