#ifndef ENEMY_H
#define ENEMY_H

// Enemy struct
typedef struct Enemy {
    char *name;
    int maxHealth;
    int currentHealth;
    int strength;

    // Function pointers for attacks
    int (*attackFirst)(struct Enemy *enemy);
    int (*attackSecond)(struct Enemy *enemy);
    int (*attackThird)(struct Enemy *enemy);
} Enemy;

// Function prototypes
Enemy createEnemy(const char *name, int health, int strength, 
                  int (*attack1)(Enemy *),
                  int (*attack2)(Enemy *),
                  int (*attack3)(Enemy *));
void takeDamageEnemy(Enemy *enemy, int damage);
int attackEnemy(Enemy *enemy, int roll);

#endif // ENEMY_H