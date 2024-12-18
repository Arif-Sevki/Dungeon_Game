#include "room.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Function to create a new room
Room* createRoom(const char* description) {
    Room* newRoom = (Room*)malloc(sizeof(Room)); // Allocate memory for the new room
    if (!newRoom) {
        printf("Memory allocation failed for room.\n");
        exit(1);
    }

    strncpy(newRoom->description, description, DESCRIPTION_LENGTH - 1); // Set the description
    newRoom->description[DESCRIPTION_LENGTH - 1] = '\0'; // Ensure null termination

    // Initialize room contents
    newRoom->items[0] = (Item){"None", 0, 0, 0}; // No item by default
    newRoom->enemies[0] = (Enemy){NULL, 0, 0, 0, NULL, NULL, NULL}; // No enemy by default

    // Set all neighboring rooms to NULL initially
    newRoom->up = NULL;
    newRoom->down = NULL;
    newRoom->left = NULL;
    newRoom->right = NULL;

    return newRoom;
}

// Function to add an item to a room
void addItemToRoom(Room* room, Item item) {
    room->items[0] = item; // Add the item to the room
    printf("Item '%s' added to the room.\n", item.name);
}

// Function to add an enemy to a room
void addEnemyToRoom(Room* room, Enemy enemy) {
    room->enemies[0] = enemy; // Add the enemy to the room
    printf("Enemy '%s' added to the room.\n", enemy.name);
}

// Function to connect two rooms in a specific direction
void connectRooms(Room* room1, Room* room2, const char* direction) {
    if (strcmp(direction, "up") == 0) {
        room1->up = room2;
        room2->down = room1;
    } else if (strcmp(direction, "down") == 0) {
        room1->down = room2;
        room2->up = room1;
    } else if (strcmp(direction, "left") == 0) {
        room1->left = room2;
        room2->right = room1;
    } else if (strcmp(direction, "right") == 0) {
        room1->right = room2;
        room2->left = room1;
    } else {
        printf("Invalid direction: %s. Use 'up', 'down', 'left', or 'right'.\n", direction);
    }
}

// Function to print room details
void printRoomDetails(const Room* room) {
    printf("Room Description: %s\n", room->description);

    // Print item details
    if (strcmp(room->items[0].name, "None") != 0) {
        printf("Item in Room: %s (Health Bonus: %d, Strength Bonus: %d)\n",
               room->items[0].name, room->items[0].healthBonus, room->items[0].strengthBonus);
    } else {
        printf("No item in this room.\n");
    }

    // Print enemy details
    if (room->enemies[0].name != NULL) {
        printf("Enemy in Room: %s (Health: %d, Strength: %d)\n",
               room->enemies[0].name, room->enemies[0].currentHealth, room->enemies[0].strength);
    } else {
        printf("No enemy in this room.\n");
    }

    // Print neighboring rooms
    printf("Connections:\n");
    if (room->up) printf("  Up: %s\n", room->up->description);
    if (room->down) printf("  Down: %s\n", room->down->description);
    if (room->left) printf("  Left: %s\n", room->left->description);
    if (room->right) printf("  Right: %s\n", room->right->description);
}
