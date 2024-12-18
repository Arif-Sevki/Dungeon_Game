#include "room.h"
#include "enemy.h"
#include "goblin.h"
#include "skeletonSoldier.h"
#include "zombie.h"
#include "orc.h"
#include "ghost.h"
#include "giantBear.h"
#include "vampire.h"
#include "werewolf.h"
#include "spiderQuenn.h"
#include "finalboss.h"


Room *dungeon[33]; // Array to hold all rooms in the dungeon

void initializeDungeon() {
    
    // Enemy initialization
    //easy
    Enemy goblin = createGoblin(2,20);
    Enemy skeletonSoldier = createSkeletonSoldier( 7,25);
    Enemy zombie = createZombie(5,40);
    //normal
    Enemy orc = createOrc( 8,100);
    Enemy ghost = createGhost( 10,60);
    Enemy giantBear = createBear( 12,120);
    //hard
    Enemy vampire = createVampire( 15,300);
    Enemy werewolf = createWerewolf( 20,200);
    Enemy spiderQuenn = createSpiderQuenn( 22,240);
    //final boss
    Enemy finalBoss = createBoss( 30,500);

    printf("Enemies initialized.\n");

    //Item initialization
    //low quality
    Item treasure1  = {"Ring of the Ancient Kings(str+3)", 0, 3,1};
    Item treasure2  = {"Moonlit Crown(str+4)", 0, 4,1};
    Item treasure3  = {"Seal of Darkness(str+5)", 0, 5,1};
    Item treasure4  = {"Call of the Stars(hp+25)", 25, 0,1};
    Item treasure5  = {"Shadowstone Band(hp+15)", 15, 0,1};
    Item treasure6  = {"Emerald Circle(hp+5,str+1)", 5, 1,1};
    //medium quality
    Item treasure7  = {"Flamebinder Ring(str+10)", 0, 10,1};
    Item treasure8  = {"Stormbinder Ring(str+12)", 0, 12,1};
    Item treasure9  = {"Bloodstone Ring(str+8)", 0, 8,1};
    Item treasure10 = {"Whisper of the Depths(hp+50)", 50, 0,1};
    Item treasure11 = {"Golden Leaf Pendant(hp+60)", 60, 0,1};
    Item treasure12 = {"Heart of Time(hp+30,str+7)", 30, 7,1};
    //high quality
    Item treasure13 = {"Ring of Eternity(hp+150)", 150, 0,1};
    Item treasure14 = {"Tear of the Sun(str+20)", 0, 20,1};
    Item treasure15 = {"Key of Souls(hp+70,str+10)", 70, 10,1};
    
    printf("Items initialized.\n");
    // Room initialization

	dungeon[0] = createRoom("You are in a dark little room. It is covered with stone walls on 4 sides. There is a wooden door on the right wall. The only source of light in the room is the glowing moss");

    dungeon[1] = createRoom("You're in a stone room lit by bright moss. In front of you is a green goblin half your size. He attacks you with his dagger in his hand. There is only one door in the right wall. ");
    connectRooms(dungeon[0], dungeon[1], "right");
    addEnemyToRoom(dungeon[1], goblin);
    
    dungeon[2] = createRoom("You're in a similar stone room again. There is a table in the middle of the room and a soot ring on the table. There are doors to the right and up.");
    connectRooms(dungeon[1], dungeon[2], "right");
    addItemToRoom(dungeon[2], treasure1);

    dungeon[3] = createRoom("A skeleton is standing in front of you, looking at you. He slowly draws the arrow in his hand and prepares to fight. There are two doors up and to the right from this room.");
    connectRooms(dungeon[2], dungeon[3], "right");
    addEnemyToRoom(dungeon[3], skeletonSoldier);

    dungeon[4] = createRoom("The moment you enter the room, the smell of rotting meat fills your nose. You hear a growl in the room where almost nothing is visible. You see the body standing up where the sound comes from");
    connectRooms(dungeon[3], dungeon[4], "right");
    addEnemyToRoom(dungeon[4], zombie);

    dungeon[7] = createRoom("You enter a magnificent room. It's still the same 4 walls, but the room is much larger and there is a small opening in the ceiling. Moonlight coming from the opening hits the crown hanging on the wall");
    connectRooms(dungeon[4], dungeon[7], "down");
    addItemToRoom(dungeon[7], treasure2);

    dungeon[8] = createRoom("A skeleton is standing in front of you, looking at you. He slowly draws the arrow in his hand and prepares to fight. There are two doors up and to the right from this room.");
    connectRooms(dungeon[7], dungeon[8], "right");
    addEnemyToRoom(dungeon[8], skeletonSoldier);

    dungeon[9] = createRoom("You are in a pitch black room. While trying to find his way in the room, something hits his foot. You immediately bend down and pick up the object you found by groping.");
    connectRooms(dungeon[8], dungeon[9], "right");
    addItemToRoom(dungeon[9], treasure3);

    dungeon[10] = createRoom("You are in a very large room. The room is full of corpses. In the middle of the room, a huge bear is sleeping. The bear notices your presence with the sound of the door closing.");
    connectRooms(dungeon[9], dungeon[10], "down");
    addEnemyToRoom(dungeon[10], giantBear);

    dungeon[11] = createRoom("After passing through a corridor with fire drawings on the walls, you arrive at a bright red room. A ring stands in the middle of the room.");
    connectRooms(dungeon[10], dungeon[11], "down");
    addItemToRoom(dungeon[11], treasure7);

    dungeon[5] = createRoom("As soon as you enter the room, an ugly green giant catches your eye. It is impossible not to notice him with his big teeth, club in his hand and 3 meters tall");
    connectRooms(dungeon[9], dungeon[5], "up");
    addEnemyToRoom(dungeon[5], orc);

    dungeon[6] = createRoom("When you enter the room, a bearded middle-aged man stands up from his chair and his body begins to change. As his muscles grow, his back becomes hunched and hair begins to grow everywhere.");
    connectRooms(dungeon[5], dungeon[6], "right");
    addEnemyToRoom(dungeon[6], werewolf);

    dungeon[12] = createRoom("You enter a room filled with shiny stones that emit blue light. Where all the lights meet you find a dazzling star-studded necklace.");
    connectRooms(dungeon[2], dungeon[12], "up");
    addItemToRoom(dungeon[12], treasure4);

    dungeon[13] = createRoom("The moment you enter the room, the smell of rotting meat fills your nose. You hear a growl in the room where almost nothing is visible. You see the body standing up where the sound comes from");
    connectRooms(dungeon[12], dungeon[13], "right");
    addEnemyToRoom(dungeon[13], zombie);

    dungeon[14] = createRoom("The room you enter looks like a dojo. There are training equipment everywhere. The band on the head of one of the fighting puppets attracts your attention");
    connectRooms(dungeon[13], dungeon[14], "right");
    connectRooms(dungeon[14], dungeon[4], "down");
    addItemToRoom(dungeon[14], treasure5);

    dungeon[15] = createRoom("Before you even enter the room, you begin to hear sounds similar to thunder. When you open the door, lightning strikes over your head. After a great effort, you take the ring that is the source of the lightning.");
    connectRooms(dungeon[14], dungeon[15], "right");
    addItemToRoom(dungeon[15], treasure8);

    dungeon[16] = createRoom("The smell of blood makes you shiver. You have to try very hard not to vomit due to the intense smell. You see that a pool of blood has formed on the ground and there is a ring at the bottom of the pond. You hold your breath and take the ring");
    connectRooms(dungeon[6], dungeon[16], "up");
    addItemToRoom(dungeon[16], treasure9);

    dungeon[17] = createRoom("As you progress down the corridor, you start to feel cold. When you finally enter the room, a half-corporeal, half-spiritual figure attacks you.");
    connectRooms(dungeon[14], dungeon[17], "up");
    addEnemyToRoom(dungeon[17], ghost);

    dungeon[18] = createRoom("You follow the whispers coming to your ears along the corridor. Finally, you find yourself in front of an endless pit. You are not deceived by the sounds in your ear - jump jump - and return to reality. And a jet black necklace appears in your hand");
    connectRooms(dungeon[17], dungeon[18], "right");
    connectRooms(dungeon[18], dungeon[15], "down");
    addItemToRoom(dungeon[18], treasure10);

    dungeon[19] = createRoom("You are in a very large and dark room full of spider webs. There are spiders, small and large, all over the room. Just as he reaches the middle of the room, a giant spider jumps from the ceiling onto him.");
    connectRooms(dungeon[18], dungeon[19], "right");
    addEnemyToRoom(dungeon[19], spiderQuenn);

    dungeon[20] = createRoom("After a never-ending walk for days, you finally arrive at the room. You find a plain looking ring in the middle of his room. As you get closer, the distance between you and the ring increases. Finally you make up your mind to walk backwards and take it");
    connectRooms(dungeon[19], dungeon[20], "right");
    connectRooms(dungeon[20], dungeon[16], "down");
    addItemToRoom(dungeon[20], treasure13);

    dungeon[21] = createRoom("When you enter the room, you see a white-faced man with black hair grinning at you. He flies through the air with red wings on his back. Behind the man you can see the exit to the forest and your freedom.");
    connectRooms(dungeon[20], dungeon[21], "right");
    addEnemyToRoom(dungeon[21], finalBoss);

    dungeon[22] = createRoom("Now you are finally free. If you want, you can go back and collect all the artifacts in the dungeon, or you can leave it at this. GAME OVER!");
    connectRooms(dungeon[21], dungeon[22], "right");

    dungeon[24] = createRoom("As you progress down the corridor, you start to feel cold. When you finally enter the room, a half-corporeal, half-spiritual figure attacks you.");
    connectRooms(dungeon[19], dungeon[24], "up");
    addEnemyToRoom(dungeon[24], ghost);

    dungeon[25] = createRoom("A skeleton is standing in front of you, looking at you. He slowly draws the arrow in his hand and prepares to fight. There are two doors up and to the right from this room.");
    connectRooms(dungeon[24], dungeon[25], "right");
    connectRooms(dungeon[25], dungeon[20], "down");
    addEnemyToRoom(dungeon[25], skeletonSoldier);

    dungeon[29] = createRoom("As you progress down the corridor, the temperature rises. When you get to the room you feel like you're going to melt from the heat. Inside the room, you find a red tear among the red stones.");
    connectRooms(dungeon[24], dungeon[29], "up");
    addItemToRoom(dungeon[29], treasure14);

    dungeon[28] = createRoom("The moment you enter the room, the smell of rotting meat fills your nose. You hear a growl in the room where almost nothing is visible. You see the body standing up where the sound comes from");
    connectRooms(dungeon[29], dungeon[28], "left");
    addEnemyToRoom(dungeon[28],zombie);

    dungeon[27] = createRoom("In the middle of this room, whose walls are completely covered with gold, there is a golden leaf on the golden table.");
    connectRooms(dungeon[28], dungeon[27], "left");
    addItemToRoom(dungeon[27], treasure11);

    dungeon[26] = createRoom("As soon as you enter the room, an ugly green giant catches your eye. It is impossible not to notice him with his big teeth, club in his hand and 3 meters tall");
    connectRooms(dungeon[27], dungeon[26], "left");
    addEnemyToRoom(dungeon[26],orc);    

    dungeon[23] = createRoom("You felt like time had stopped when you came across the heart-shaped necklace in the room. It's like there's something going against the flow of time. Could this be due to the necklace?");
    connectRooms(dungeon[26], dungeon[23], "down");
    addItemToRoom(dungeon[23], treasure12);

    dungeon[30] = createRoom("You are in a beautifully decorated room. A comfortable and elegant living space. Unless you count the coffin in the corner of the room. The coffin slowly opens and a beautiful vampire attacks you.");
    connectRooms(dungeon[26], dungeon[30], "up");
    addEnemyToRoom(dungeon[30],vampire);

    dungeon[31] = createRoom("A very simple room in one of the deepest corners of the labyrinth. And an ordinary emerald in the room");
    connectRooms(dungeon[30], dungeon[31], "right");
    addItemToRoom(dungeon[31], treasure6);

    dungeon[32] = createRoom("You were filled with enthusiasm when you entered this room. You have come across the work that will reward you for all your suffering. That work that will enable you to rule all of humanity. key of soul");
    connectRooms(dungeon[31], dungeon[32], "up");
    addItemToRoom(dungeon[32], treasure15);

}