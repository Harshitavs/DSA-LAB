//split singly list alternatively
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createList (int n){
    struct node *head = NULL ,*temp = NULL, *newnode ;
  int data;

  for (int i = 0;i<n;i++){
    scanf("%d",&data);
    newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
     if(head == NULL){
     head = newnode;
        temp = newnode;
     } else {
        temp->next = newnode;
        temp = newnode;
     }
    }
  return head;
}
void split_alternatively(struct node* head){
    struct node* head1 = NULL, *temp1 = NULL;
    struct node* head2 = NULL , *temp2 = NULL;

    struct node* temp = head;
    int count = 0;
    
    while(temp != NULL){
        if (count % 2==0){
            if(head1 == NULL){
                head1 = temp;
                temp1 = temp;
            } else {
                temp1->next = temp;
                temp1 = temp;
            }
        } else {
            if(head2 == NULL){
                head2 = temp;
                temp2 = temp;
            } else {
                temp2->next = temp;
                temp2 = temp;
            }
        }
        temp = temp->next;
        count++;
    }
    if(temp1) temp1->next = NULL;
    if(temp2)temp2->next = NULL;

    printf("First list:");
    temp = head1;
    while(temp){
        printf("%d->",temp->data);
        temp =temp->next;
    }
    printf("NULL\n");

     printf("Second list:");
    temp = head2;
    while(temp){
        printf("%d->",temp->data);
        temp =temp->next;
    }
    printf("NULL\n");
}
int main(){ 
    int n;
    printf("Enter number of nodes:");
    scanf("%d",&n);

    struct node* head = createList(n);

    split_alternatively(head);
}