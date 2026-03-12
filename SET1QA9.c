#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createList(int n){

    struct node *head = NULL, *temp = NULL, *newnode;
    int x;

    for(int i=0;i<n;i++){
        scanf("%d",&x);  
        newnode = malloc(sizeof(struct node));
        newnode-> data = x;
        newnode->prev = NULL;
        newnode->next = NULL;
        
        if (head == NULL){
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
         }
    return head;
}
struct node* reverse(struct node* head){
    struct node *temp = NULL, *current = head;

    while(current != NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }
    if(temp != NULL)
        head =temp ->prev;

        return head;
}
void display(struct node* head){
      while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main(){
    int n;
    printf("Enter number of nodes:");
    scanf("%d",&n);

    struct node* head = createList(n);

    head = reverse(head);

    display(head);
}
