#include "map.h"


void initializeMap(Map *map) {
    // Starting map
    char initialMap[MAP_HEIGHT][MAP_WIDTH] = {
        {' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '.', '.', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', '.', '.', '.', '.', ' ', ' ', ' '},
        {' ', ' ', ' ', '.', ' ', ' ', '.', '.', ' ', ' '},
        {' ', ' ', ' ', ' ', '.', '.', '.', '.', '.', '.'},
        {' ', ' ', '.', '.', '.', '.', ' ', '.', ' ', ' '},
        {'C', '.', '.', '.', '.', ' ', '.', '.', ' ', ' '},
        {' ', ' ', ' ', ' ', '.', '.', '.', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', ' '}
    };

    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            map->grid[i][j] = initialMap[i][j]; // Coppy the initial map
        }
    }
    map->currentX = 0; 
    map->currentY = 6; 
}

void printMap(const Map *map) {
    for (int i = 0; i < MAP_HEIGHT; i++) {
        for (int j = 0; j < MAP_WIDTH; j++) {
            printf("%c ", map->grid[i][j]);
        }
        printf("\n");
    }
}


int moveCharacter(Map *map, int dx, int dy) { //(1,0)->right, (-1,0)->left, (0,1)->down, (0,-1)->up
    int newX = map->currentX + dx;
    int newY = map->currentY + dy;

    // Is the new position within the map?
    if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT) {
        // Is the new position a path?
        if (map->grid[newY][newX] == PATH||map->grid[newY][newX] == VISITED) {
            // Make the last position visited
            if (map->grid[map->currentY][map->currentX] == CURRENT) {
                map->grid[map->currentY][map->currentX] = VISITED;
            }

            // Update the current position
            map->currentX = newX;
            map->currentY = newY;
            map->grid[map->currentY][map->currentX] = CURRENT; 

            return 1;
        }
    }

    return 0; 
}