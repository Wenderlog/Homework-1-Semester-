#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertSorted(struct Node** head,int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || data <(*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current -> next;
    }
    newNode->next = newNode;
    current->next = newNode;
}

void delete(struct Node** head, int data) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == data) {
        struct Node* tmp = *head;
        *head =(*head)->next;
        free(tmp);
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next == NULL) {
        return;
    }

    struct Node* tmp = current->next;
    current->next = current->next->next;
    free(tmp);

}

void printList(struct Node* head) {
    struct Node* current = head;
    printf("Список - ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main() {
    struct Node* list = NULL;
    int choice = 0;
    int value = 0;

    do {
        printf("Выберите операцию: \n");
        printf("0 - выйти \n");
        printf("1 - добавить значение в сортированный список \n");
        printf("2 - удалить значение из списка \n");
        printf("3 - распечатать список \n");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                break;
            case 1:
                printf("Введите значение для добавления ");
                scanf("%d", &value);
                insertSorted(&list, value);
                break;
            case 2:
                printf("Введите значение для удаления ");
                scanf("%d", &value);
                delete(&list, value);
                break;
            case 3:
                printList(list);
                break;

            default:
                printf("Неверный выбор");
        }
    } while (choice != 0);

    while (list != NULL) {
        struct Node* tmp = list;
        list = list->next;
        free(tmp);
    }

    return 0;
}
