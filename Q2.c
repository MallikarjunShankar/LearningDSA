#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void createNode(struct Node **head, struct Node **tail, int value) {
    if (*head == NULL) {
        *head = (struct Node*)malloc(sizeof(struct Node));
        (*head)->data = value;
        (*head)->next = NULL;
        *tail = *head;
    } else {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void deleteNode(struct Node **head, struct Node **tail, int value) {
    struct Node *current = *head;
    struct Node *previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == *tail) {
                *tail = previous;
            }

            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("Node not found.\n");
}

void displayList(struct Node *head) {
    struct Node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        createNode(&head, &tail, value);
    }

    int choice = 0;

    do {
        printf("1. Display List\n2. Delete Node\n3. Insert Node\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayList(head);
                break;

            case 2: {
                int value;
                printf("Enter value for deletion: ");
                scanf("%d", &value);
                deleteNode(&head, &tail, value);
                break;
            }

            case 3: {
                int value;
                printf("Enter value for insertion: ");
                scanf("%d", &value);
                createNode(&head, &tail, value);
                break;
            }

            case 4:
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}