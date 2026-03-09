#include<stdio.h>
#include<stdlib.h>

struct node  { 
    int data;
    struct node* next;
};

struct node* createList(int n){
    struct node *head = NULL, *temp = NULL,*newnode;
  int x;

  
  for (int i=0;i<n;i++){
    printf("Enter  %d element: ", i+1);
    scanf("%d",&x);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        temp = newnode;
    }
    else {
        temp->next = newnode;
        temp = newnode;
    }
  }
  return head;
}

int check_circular (struct node* head){
    if(head == NULL)
      return 0;

    struct node* temp = head->next;
    while (temp != NULL && temp !=head){
        temp=temp->next;
    }
    if (temp == head)
        return 1;
        else 
        return 0;
}

int main(){
    int n,choice;
    printf("Enter numbr of nodes:");
    scanf("%d",&n);

    struct node* head = createList(n);
     printf("Make circular? (1=yes 0=no): ");
    scanf("%d",&choice);

    if(choice==1){

        struct node* temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}

temp->next = head;
    }
if (check_circular(head)){
    printf("Circular linked list");
  }  else {
    printf("Not circular");
}
}