#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node* CreateList (int n){
    struct node *head = NULL, *temp = NULL, *newnode;
    int x;
    for (int i=0;i<n;i++){
        scanf("%d",&x);
        newnode = malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
    
    if (head == NULL){
        head = newnode;
        temp = newnode;
    } else {
        temp->next = newnode;
        temp = newnode;
    }
}
    return  head;
}
void CheckLength (struct node* head){
    struct node* temp = head;
    int count=0;
    while (temp != NULL){
        count++;
        temp= temp->next;
    }
    if ( count % 2 == 0){
        printf("Length is even.");
    } else 
    printf("Length is odd");
}
int main (){
    int n;

    printf("Enter number of nodes:");
     scanf("%d",&n);
     struct node* head =  CreateList(n);

     CheckLength(head);
}
