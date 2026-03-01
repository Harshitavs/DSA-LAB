#include<stdio.h>
#include<stdlib.h>
struct node {
    int data ;
    struct node* next;
};

struct node* reverse(struct node* head){
    if( head == NULL || head->next == NULL)
    return head ;

    struct node* newHead = reverse(head->next);
    head->next->next = head ;
    head->next = NULL;
    return newHead;
}
void display(struct node* head){
    printf("Reversed list is:");
    while(head ){
       
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int n , data;
    struct node *head  = NULL , *temp = NULL, *newnode;

   printf("Enter no of node :");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
     printf("Enter data for %d node:" , i+1);
        scanf("%d",&data);
        newnode = malloc(sizeof(struct node));
        newnode ->data = data;
        newnode->next = NULL;

        if(!head)head = temp = newnode;
        else{
            temp->next = newnode ;
            temp = newnode; 
        }
    }
    head = reverse(head);
    display(head);
}