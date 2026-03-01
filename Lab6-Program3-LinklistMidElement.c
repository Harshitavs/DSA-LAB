#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};
 int middleELE(struct node* head){
    struct node *slow = head, *fast = head;

    while(fast && fast-> next){
        slow = slow-> next;
        fast = fast->next->next;
    }
    return slow->data;
 }
 int main(){
    int n , data;
    struct node *head = NULL, *temp =NULL , *newnode;

    printf("Enter number of nodes:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
         printf("Enter data for %d node:" , i+1);
        scanf("%d",&data);
        newnode = malloc(sizeof(struct node));
        newnode ->data = data;
        newnode->next = NULL;
        if (!head) head = temp = newnode;
        else {
      temp-> next = newnode;
  temp = newnode;
        }
    }
    printf("Middle element = %d\n " , middleELE(head));
 }