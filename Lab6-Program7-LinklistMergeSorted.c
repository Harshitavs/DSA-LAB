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

        printf("Enter value (sorted order): ");
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


struct node* merge(struct node* l1, struct node* l2) {

    if(l1 == NULL)
        return l2;

    if(l2 == NULL)
        return l1;

    if(l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

int main() {

    printf("Create First Sorted List\n");
    struct node* list1 = createList();

    printf("\nCreate Second Sorted List\n");
    struct node* list2 = createList();

    printf("\nFirst List:\n");
    display(list1);

    printf("Second List:\n");
    display(list2);

    struct node* merged = merge(list1, list2);

    printf("\nMerged Sorted List:\n");
    display(merged);

    return 0;
}