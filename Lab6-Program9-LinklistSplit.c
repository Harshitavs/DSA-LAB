#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};


struct node* createList() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &value);

        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node* head) {
    while(head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


void splitAtPosition(struct node* head, int pos,
                     struct node** first,
                     struct node** second) {

    if(head == NULL || pos <= 0) {
        *first = NULL;
        *second = NULL;
        return;
    }

    struct node* temp = head;

    for(int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        *first = head;
        *second = NULL;
        return;
    }

    *first = head;
    *second = temp->next;
    temp->next = NULL;   
}

int main() {

    struct node *head = createList();
    struct node *first = NULL, *second = NULL;
    int pos;

    printf("\nOriginal List:\n");
    display(head);

    printf("\nEnter position to split: ");
    scanf("%d", &pos);

    splitAtPosition(head, pos, &first, &second);

    printf("\nFirst Part:\n");
    display(first);

    printf("\nSecond Part:\n");
    display(second);

    return 0;
}