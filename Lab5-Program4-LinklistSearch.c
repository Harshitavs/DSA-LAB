
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node *next ;
};
int search_element (struct node *head,int key  ){
    struct node *temp = head ; 
    int position =1;
    while( temp != NULL){
          if  (temp ->data == key){
           return position ;
    }
       temp = temp->next;
       position++;
}
return -1;
}
int main(){
    struct node *head = NULL , *temp = NULL , *newnode = NULL;
    int n , data;

    printf("Enter number of nodes :");
    scanf("%d" ,&n);

for(int i=0;i<n;i++){
    printf("Enter data for node %d:" , i+1);
    scanf("%d",&data );

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL){
        head = newnode;
        temp = head;
    } else 
    {temp->next  = newnode ;
        temp = newnode;
    }
}
int key;
printf("Enter element to search:" );
scanf("%d",&key);

int result = search_element(head , key);
if(result == -1){
    printf("Element not found in linklist.");
}
else {
    printf("Element found at position  %d .\n"  , result);
}
return 0;
}