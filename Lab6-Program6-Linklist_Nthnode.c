#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createList() {
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
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

struct node* nthFromEnd(struct node* head, int n) {
    struct node *first = head, *second = head;

    for(int i = 0; i < n; i++) {
        if(first == NULL)
            return NULL;
        first = first->next;
    }

    while(first) {
        first = first->next;
        second = second->next;
    }

    return second;
}

int main() {

    struct node* head = createList();

    printf("Linked List:\n");
    display(head);

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    struct node* result = nthFromEnd(head, n);

    if(result)
        printf("%dth node from end is: %d\n", n, result->data);
    else
        printf("Invalid position\n");

    return 0;
}