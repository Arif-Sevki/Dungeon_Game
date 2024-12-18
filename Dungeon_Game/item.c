#include "item.h"
#include <stdio.h>
#include <string.h>

// Initialize the inventory
void initializeInventory(Inventory *inventory) {
    inventory->itemCount = 0; // Start with no items
}

// Add an item to the inventory
int addItem(Inventory *inventory, Item newItem) {
    if (inventory->itemCount < MAX_INVENTORY_SIZE) {
        inventory->items[inventory->itemCount] = newItem; // Add the new item
        inventory->itemCount++; // Increase the item count
        return 1; // Successfully added
    } else {
        // Inventory is full, prompt user to replace an item
        printf("Inventory is full! You need to replace an existing item.\n");
        printInventory(inventory); // Show current inventory

        int index;
        printf("Enter the index of the item you want to replace (1 to %d): ", MAX_INVENTORY_SIZE);
        scanf("%d", &index);
        index--; // Adjust for 0-based index

        if (index >= 0 && index < MAX_INVENTORY_SIZE) {
            inventory->items[index] = newItem; // Replace the item
            printf("Replaced item at index %d with %s.\n", index + 1, newItem.name);
            return 1; // Successfully replaced
        } else {
            printf("Invalid index! Item not added.\n");
            return 0; // Failed to add
        }
    }
}

// Remove an item from the inventory by index
void removeItem(Inventory *inventory, int index) {
    if (index >= 0 && index < inventory->itemCount) {
        for (int i = index; i < inventory->itemCount - 1; i++) {
            inventory->items[i] = inventory->items[i + 1]; // Shift items left
        }
        inventory->itemCount--; // Decrease item count
    }
}

// Print the contents of the inventory
void printInventory(const Inventory *inventory) {
    printf("Inventory:\n");
    for (int i = 0; i < inventory->itemCount; i++) {
        printf("%d: %s (Health Bonus: %d, Strength Bonus: %d, Stack Count: %d)\n",
               i + 1, inventory->items[i].name,
               inventory->items[i].healthBonus,
               inventory->items[i].strengthBonus,
               inventory->items[i].stackCount);
    }
}

// Find an item in the inventory by name
int findItem(const Inventory *inventory, const char *itemName) {
    for (int i = 0; i < inventory->itemCount; i++) {
        if (strcmp(inventory->items[i].name, itemName) == 0) {
            return i; // Return index of the item
        }
    }
    return -1; // Item not found
}