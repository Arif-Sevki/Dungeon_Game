#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

// Map characters
#define EMPTY ' '   // Outside of the map
#define VISITED 'x' // Visited path
#define CURRENT 'C' // Current location
#define PATH '.'     // Rooms

// Map struct
typedef struct {
    char grid[MAP_HEIGHT][MAP_WIDTH];
    int currentX;
    int currentY;
} Map;

// Map function prototypes
void initializeMap(Map *map);
void printMap(const Map *map);
int moveCharacter(Map *map, int dx, int dy);

#endif 