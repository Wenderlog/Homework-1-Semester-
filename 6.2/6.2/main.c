#include <stdlib.h>
#include <stdio.h>

struct Warrior {
    int number;
    struct Warrior* next;
};

struct Warrior* createWarrior(int num) {
    struct Warrior* newWarrior = (struct Warrior*)malloc(sizeof(struct Warrior));
    newWarrior->number = num;
    newWarrior->next = NULL;
    return  newWarrior;
}

struct Warrior* createWarriorCircle(int n) {
    if (n < 0) {
        return NULL;
    }
    struct Warrior* head = createWarrior(1);
    struct Warrior* current = head;
    
    for (int i = 2; i <= n; i++) {
        current->next = createWarrior(i);
        current = current->next;
    }
    
    current->next = head;
    
    return head;
}

int findSurvivor(int n, int m) {
    if (n <= 0 && m <= 0) {
        return -1;
    }
    
    struct Warrior* circle = createWarriorCircle(n);
    struct Warrior* prev = circle;
    struct Warrior* current = circle;
    
    while (current->next != current) {
        for (int i = 0; i < m - 1; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        struct Warrior* tmp = current;
        current = current->next;
        free(tmp);
    }
    
    int survivorNumber = current->number;
    free(current);
    return survivorNumber;
}


int main() {
    int n = 0;
    int m = 0;
    printf("Введите кол-во воинов ");
    scanf("%d", &n);
    printf("Введите кол-во убийств ");
    scanf("%d", &m);
    
    int survivor = findSurvivor(n, m);
    
    if (survivor != -1) {
        printf("Воин под номером %d останется последним \n", survivor);
    } else {
        printf("Некоректно ввели данные\n");
    }
    return 0;
}
