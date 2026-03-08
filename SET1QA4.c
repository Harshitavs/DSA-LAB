#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void createlist(struct node** head , int n){
    if(n<=0){
        *head = NULL;
        return ;
    }
    int data;
    struct node* temp ;
    struct node* newnode;

    printf("Enter data for node 1:");
        scanf("%d" ,&data);
        *head = (struct node*)malloc(sizeof(struct node));
        (*head)->data = data;
        (*head)->next = NULL;
        temp = *head;

        for(int i = 2;i<= n;i++){
        printf("Enter data for node %d:",i);
        scanf("%d",&data);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
        }
}
        void insert_atstart(struct node** head, int data){
        struct node* newnode = (struct 
         node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = *head;
        *head = newnode;
    }
        void insert_atEnd(struct node** head ,int data){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data =data;
        newnode-> next =NULL;
        if(*head == NULL){
        *head = newnode;
        return;
    }
        struct node* temp = *head;
        while(temp->next != NULL){
        temp = temp->next;
    }
        temp->next = newnode;
    }
void insert_atposition(struct node** head, int value , int position){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if(position == 0){
        newnode->next = *head;
        *head = newnode;
        return ;
    }
    struct node* temp = *head;
    for(int i=0;i < position -1 && temp != NULL ; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Positon out of range\n");
        free(newnode);
        return;
    }
    newnode->next  =temp->next;
    temp->next  = newnode;
}
void printList(struct node *head){
    struct node *temp = head;
while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
     struct node* head = NULL;
    int choice, data, position, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List of n nodes\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

switch(choice){
    case 1:
    printf("Enter number of nodes:");
    scanf("%d",&n);
    createlist(&head,n);
    break;
    case 2:
    printf("Enter value :");
    scanf("%d", &data);
    insert_atstart(&head , data);
    break;
    case 3:
    printf("Enter value:");
    scanf("%d", &data);
    insert_atEnd(&head ,data);
    break;
    case 4 :
    printf("Enter value:");
    scanf("%d", &data);
    printf("Enter position:");
    scanf("%d",&position);
    insert_atposition(&head,data,position);
    break;
    case 5:
    printList(head);
    break;
    case 6:
    exit(0);
    default :
    printf("plesse choose from 1 to 6\n");
}
    }
    return 0;
}