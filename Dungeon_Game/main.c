//Arif Şevki Yılmaz
//22050111043

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "room.h"
#include "enemy.h"
#include "player.h"
#include "dungeon.h"
#include "map.h"

extern Room *dungeon[33]; // Array to hold all rooms in the dungeon
static Player player; // Global player variable
Map gameMap; // Global map variable

void applyInventoryBonuses(Player *player);
void removeInventoryBonuses(Player *player);
void showStatus();
void initializeDungeon();
void initializeMap(Map *map);
void printMap(const Map *map);
void printCurrentRoom();
void processCommand(char *command);
void look();
void move(char *direction);
void showInventory();
void combat(Enemy *enemy);
int rollDice();

int main() {
    srand(time(NULL)); // Seed the random number generator




    // Initialize the dungeon and player
    initializeDungeon();
    player = createPlayer(100, 10); 
    player.currentRoom = dungeon[0];
    printf("Player created with %d health and %d strength.\n", player.currentHealth, player.strength);

    initializeMap(&gameMap);
    printf("Map initialized.\n");

    char command[50];

    printf("Welcome to the Dungeon Adventure!\n");
    printf("You are the 3rd Prince of the Empire. To seize the throne and rule humanity you need to find the Key of the souls\n");
    printf("You entered a dungeon to find this item and lost your way. Continue your way through the dungeon and find the exit.\n");
    printf("Type 'help' for a list of commands.\n");

    while(1){

        printf("Enter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; 

        processCommand(command);
    }

    return 0;
}

void printCurrentRoom() {
    if (player.currentRoom != NULL) {
        printf("%s\n", player.currentRoom->description);
        // List enemies in the room if any
        if (player.currentRoom->enemies[0].name) {
            printf("You see a %s here!\n", player.currentRoom->enemies[0].name);
        }
    } else {
        printf("You are in an undefined room.\n");
    }
}

void processCommand(char *command) {
    if (strcmp(command, "look") == 0) {
        look();
    } else if (strcmp(command, "inventory") == 0) {
        printInventory(&player.inventory);
    } else if (strcmp(command, "status") == 0) {
        showStatus();
    } else if (strcmp(command, "up") == 0) {
        move("up");
        moveCharacter(&gameMap, 0,-1);
    } else if (strcmp(command, "down") == 0) {
        move("down");
        moveCharacter(&gameMap, 0, 1);
    } else if (strcmp(command, "left") == 0) {
        move("left");
        moveCharacter(&gameMap,-1, 0);
    } else if (strcmp(command, "right") == 0) {
        move("right");
        moveCharacter(&gameMap, 1, 0);
    } else if (strcmp(command, "map") == 0) {
        printMap(&gameMap); 
    } else if (strcmp(command, "help") == 0) {
        printf("Available commands: look, inventory, up, down, left, right, map, status, exit, help\n");
    } else if (strcmp(command, "exit") == 0) {
        printf("Exiting the game. Goodbye!\n");
        exit(0); 
    } else {
        printf("Unknown command: %s\n", command);
    }
}

void look() {
    printf("You look around: %s\n", player.currentRoom->description);
}

void move(char *direction) {
    Room *nextRoom = NULL;

    if (strcmp(direction, "up") == 0) {
        nextRoom = player.currentRoom->up;
    } else if (strcmp(direction, "down") == 0) {
        nextRoom = player.currentRoom->down;
    } else if (strcmp(direction, "left") == 0) {
        nextRoom = player.currentRoom->left;
    } else if (strcmp(direction, "right") == 0) {
        nextRoom = player.currentRoom->right;
    }

    if (nextRoom) {
        player.currentRoom = nextRoom;
        printf("You move %s.\n", direction);

        // Check for combat if there is an enemy in the new room
        if (nextRoom->enemies[0].name) {
            combat(&nextRoom->enemies[0]);
        }

        // Check for items in the room
        if (strcmp(nextRoom->items[0].name, "None") != 0) {
            printf("You found a %s!\n", nextRoom->items[0].name);
            removeInventoryBonuses(&player); // Remove old inventory bonuses
            // Add the item to the player's inventory
            addItem(&player.inventory, nextRoom->items[0]);
            applyInventoryBonuses(&player); // Apply new inventory bonuses
            // Reset the item in the room to "None"
            nextRoom->items[0] = (Item){"None", 0, 0, 0}; // Reset item
        }
    } else {
        printf("You can't go that way!\n");
    }
}


void showInventory() {
    printf("You have the following items:\n");
    for (int i = 0; i < 5; i++) {
        printf("- %s\n", player.inventory.items[i].name);
    }
}

void combat(Enemy *enemy) {
    printf("A  %s appears!\n", enemy->name);
    while (player.currentHealth > 0 && enemy->currentHealth > 0) {
        // Player's turn
        int roll = rollDice();
        printf("You roll %d \n", roll);
        takeDamageEnemy(enemy, attack(roll));

        if (enemy->currentHealth <= 0) {
            printf("You defeated the %s!\n", enemy->name);
            player.currentHealth = player.maxHealth; // Fully heal the player
            break;
        }

        // Enemy's turn
        int enemyRoll = rollDice();
        printf("Enemy roll %d \n", enemyRoll);
        player.currentHealth-=attackEnemy(enemy, enemyRoll);

        if (player.currentHealth <= 0) {
            printf("You have been defeated by the %s!\n", enemy->name);
            exit(0); // End the game if the player is defeated
        }

        printf("Your current health: %d\n", player.currentHealth);
        printf("Enemy's remaining health: %d\n", enemy->currentHealth);
    }
}

int rollDice() {
    return rand() % 6 + 1;
}

void showStatus() {
    printf("\n--- Player Status ---\n");
    printf("Health: %d/%d\n", player.currentHealth, player.maxHealth);
    printf("Strength: %d\n", player.strength);
    
    printf("\n");
}

void applyInventoryBonuses(Player *player) {
    int totalHealthBonus = 0;
    int totalStrengthBonus = 0;

    // Iterate over the inventory and sum up the bonuses
    for (int i = 0; i < player->inventory.itemCount; i++) {
        totalHealthBonus += player->inventory.items[i].healthBonus;
        totalStrengthBonus += player->inventory.items[i].strengthBonus;
    }

    // Apply the total bonuses to the player's stats
    player->maxHealth += totalHealthBonus;
    player->currentHealth += totalHealthBonus;
    player->strength += totalStrengthBonus;

    
}

void removeInventoryBonuses(Player *player) {
    int totalHealthBonus = 0;
    int totalStrengthBonus = 0;

    // Iterate over the inventory and sum up the bonuses
    for (int i = 0; i < player->inventory.itemCount; i++) {
        totalHealthBonus += player->inventory.items[i].healthBonus;
        totalStrengthBonus += player->inventory.items[i].strengthBonus;
    }

    // Remove the total bonuses from the player's stats
    player->maxHealth -= totalHealthBonus;
    player->currentHealth -= totalHealthBonus;
    player->strength -= totalStrengthBonus;

    
}