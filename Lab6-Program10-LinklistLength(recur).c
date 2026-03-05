
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

int length(struct node* head) {
    if(head == NULL)
        return 0;
    return 1 + length(head->next);
}

int main() {

    struct node* head = createList();

    printf("Linked List:\n");
    display(head);

    printf("Length of list (recursive): %d\n", length(head));

    return 0;
}