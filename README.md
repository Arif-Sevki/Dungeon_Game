##Dungeon Adventure Game

https://docs.google.com/document/d/1Hb0QPo_0bUFklgshV7GuyNPGEBPK51mINCrQHsJYQbA/edit?tab=t.0

#Overview

Dungeon Adventure is a text-based role-playing game where players explore a dungeon, interact with enemies, collect items, and navigate through rooms. The game is built using C and follows a modular structure, with different source files managing various aspects of the game, such as the map, player, items, and enemies.

#Features

Player Stats: Health, strength, and inventory system that directly affect gameplay.

Inventory Management: Add, replace, and remove items, each affecting the player's attributes.

Dynamic Map: Navigate through rooms and explore the dungeon.

Enemy Encounters: Interact with enemies in the dungeon.

Commands: Simple text-based commands for interaction.

#File Structure

project/ ├── dungeon.c # Manages dungeon mechanics ├── enemy.c # Handles enemy interactions ├── item.c # Defines and manages items ├── main.c # Entry point and main game loop ├── map.c # Handles the dungeon map ├── player.c # Manages player stats and inventory ├── room.c # Handles room-specific logic ├── Makefile # Build instructions

#Compilation

The project uses gcc for compilation. You can build the game using the provided Makefile.

#Build Instructions

Open a terminal and navigate to the project directory.

Run the following command to build the game:

make

To clean up generated files (object files and executable), use:

make clean

#Manual Compilation

If you prefer not to use the Makefile, you can manually compile the game using:

gcc dungeon.c enemy.c item.c main.c map.c player.c room.c -o Run

#How to Play

Run the game executable:

./Run

Enter commands to interact with the game world. Example commands:

look: Examine the current room.

inventory: View your inventory.

status: Check your health and strength.

up, down, left, right: Move through the dungeon.

help: Display available commands.

exit: Quit the game.

#Contribution

Feel free to contribute to the project by submitting pull requests or reporting issues. Suggestions for new features and enhancements are always welcome.

#Credits

Designed and implemented by Arif Şevki YILMAZ (std id: 22050111043)
