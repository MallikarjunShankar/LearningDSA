#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;
    
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        } 
    }

    printf("The linked list is: ");
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    int choice;
    printf("Select operation: (insert - 1/delete - 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for new node; ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    } else if (choice == 2) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        printf("Invalid choice.");
    }

    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}