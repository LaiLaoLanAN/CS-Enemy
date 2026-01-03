#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Enemy {
    char name[20];
    int damage;
    int mp;
    struct Enemy* next;
};

struct Enemy* createEnemy(char* name, int damage, int mp) {
    struct Enemy* newEnemy = (struct Enemy*)malloc(sizeof(struct Enemy));
    strcpy(newEnemy->name, name);
    newEnemy->damage = damage;
    newEnemy->mp = mp;
    newEnemy->next = NULL;
    return newEnemy;
}

void printEnemies(struct Enemy* head) {
    struct Enemy* current = head;
    while (current != NULL) {
        printf("Name: %s, Damage: %d, MP: %d\n",
            current->name, current->damage, current->mp);
        current = current->next;
    }
}

int main() {
    struct Enemy* head = createEnemy("Goblin", 10, 5);
    head->next = createEnemy("Orc", 25, 15);
    head->next->next = createEnemy("Dragon", 50, 30);

    printEnemies(head);

    return 0;
}