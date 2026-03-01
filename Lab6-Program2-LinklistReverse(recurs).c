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

struct node* reverse(struct node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    struct node* rest = reverse(head->next);

    head->next->next = head;
    head->next = NULL;

    return rest;
}

int main() {

    struct node* head = createList();

    printf("Original List:\n");
    display(head);

    head = reverse(head);

    printf("Reversed List:\n");
    display(head);

    return 0;
}