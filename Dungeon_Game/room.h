#ifndef ROOM_H
#define ROOM_H

#include "item.h"
#include "enemy.h"

#define DESCRIPTION_LENGTH 256

// Room structure

typedef struct Room {
    char description[DESCRIPTION_LENGTH]; // Fixed-size array for description
    struct Room *up;
    struct Room *down;
    struct Room *left;
    struct Room *right;
    Item items[10]; // Array to hold items in the room
    Enemy enemies[10]; // Array to hold enemies in the room
} Room;

// Function prototypes
Room* createRoom(const char* description);
void addItemToRoom(Room* room, Item item);
void addEnemyToRoom(Room* room, Enemy enemy);
void connectRooms(Room* room1, Room* room2, const char* direction);
void printRoomDetails(const Room* room);
void freeRoom(Room* room); // Function to free dynamically allocated memory for the room

#endif // ROOM_H