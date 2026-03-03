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


void createLoop(struct node* head, int pos) {
    if(pos <= 0) return;

    struct node *loopNode = NULL, *temp = head;
    int count = 1;

    while(temp->next != NULL) {
        if(count == pos)
            loopNode = temp;
        temp = temp->next;
        count++;
    }

    if(loopNode != NULL)
        temp->next = loopNode;  
}


int detectLoop(struct node* head) {
    struct node *slow = head, *fast = head;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;   
    }

    return 0;  
}
int main() {

    struct node* head = createList();
    int pos;

    printf("Enter position to create loop (0 for no loop): ");
    scanf("%d", &pos);

    createLoop(head, pos);

    if(detectLoop(head))
        printf("Loop detected in linked list.\n");
    else
        printf("No loop detected.\n");

    return 0;
}