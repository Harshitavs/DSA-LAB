#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* createList(int n){
    struct node *head = NULL, *temp =NULL, *newnode;
    int x;

    for (int i=0;i<n;i++){
        printf("Enter %d element ",i+1);
        scanf("%d",&x);

        newnode = malloc (sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL){
            head = newnode;
            temp = newnode;
        } else {
            temp-> next = newnode;
            temp = newnode;
        }
    }
    return head;
}

int loop_length(struct node* head){
    struct node *slow = head , *fast = head;
    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast ){
            int count = 1;
           struct node* temp = slow;

           while (temp->next != slow){
            count++;
            temp = temp->next;
           }
           return count;
        }

    }
    return 0;
}
int main(){
    int n, choice, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct node* head = createList(n);

    printf("Create loop? (1 = Yes / 0 = No): ");
    scanf("%d", &choice);

    if(choice == 1){
        printf("Enter position to connect last node (starting from 1): ");
        scanf("%d", &pos);

        struct node *temp = head;
        struct node *loopNode = NULL;
        int count = 1;

        while(temp->next != NULL){
            if(count == pos)
                loopNode = temp;

            temp = temp->next;
            count++;
        }

        if(count == pos)
            loopNode = temp;

        if(loopNode != NULL){
            temp->next = loopNode;
            printf("Loop created.\n");
        }
    }

    int len = loop_length(head);

    if(len > 0)
        printf("Length of loop = %d\n", len);
    else
        printf("No loop found\n");

    return 0;
}