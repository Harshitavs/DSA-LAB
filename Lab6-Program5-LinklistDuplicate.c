#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
void display(struct node* head){
    while(head != NULL){
       
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void removeDuplicate(struct node* head){
    struct node* temp= head ;

    while(temp && temp-> next){
        if(temp->data == temp->next->data){
            struct node* dup = temp->next;
            temp->next = temp->next->next;
            free(dup);
    } else { 
     
          temp =  temp-> next;
}
    }
};

int main() {
 int n , data;
    struct node *head = NULL, *temp =NULL , *newnode;

    printf("Enter number of nodes:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){

         printf("Enter data for %d node:" , i+1);
        scanf("%d",&data);

        newnode = (struct node*)malloc(sizeof(struct node));
        newnode ->data = data;
        newnode->next = NULL;

        if (!head)
         head = temp = newnode;
        else {

      temp-> next = newnode;
      temp = newnode;
        }
    }
    printf("Linklist before removing duplicates:");
    display(head);

    removeDuplicate(head);

   printf("List after removing duplicates :");
   display(head);

   return 0;
    }