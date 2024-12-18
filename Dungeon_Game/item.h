#ifndef ITEM_H
#define ITEM_H

#define MAX_INVENTORY_SIZE 5 // Maximum number of items in the inventory

// Item struct
typedef struct {
    char name[50]; // Item name
    int healthBonus; // Health increase
    int strengthBonus; // Strength increase
    int stackCount; // Number of items in the stack
} Item;

// Inventory struct
typedef struct {
    Item items[MAX_INVENTORY_SIZE]; // Array of items
    int itemCount; // Current number of items in the inventory
} Inventory;

// Function prototypes
void initializeInventory(Inventory *inventory);
int addItem(Inventory *inventory, Item newItem);
void removeItem(Inventory *inventory, int index);
void printInventory(const Inventory *inventory);
int findItem(const Inventory *inventory, const char *itemName);

#endif // ITEM_H