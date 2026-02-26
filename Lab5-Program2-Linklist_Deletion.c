
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}; void createlist(struct node** head , int n){
    if(n <= 0){
        *head = NULL;
        return;
    }
    int data;
    struct node* temp;
    struct node* newnode;

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    *head = malloc(sizeof(struct node));
    (*head)->data = data;
    (*head)->next = NULL;
    temp = *head;

    for(int i = 2; i <= n; i++){
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newnode = malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }

}
void delete_atbeg(struct node **head){
    if(*head == NULL){
        printf("List is empty:\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)-> next;
    free(temp);
}
void delete_at_end(struct node **head){
    if( *head == NULL){
        return ;
    }
if((*head)->next == NULL){
    free(*head);
     *head  = NULL;
     return;
}
struct node *temp = *head;
while(temp->next->next != NULL){
    temp = temp->next;
}
    free(temp->next);
    temp->next = NULL;
}

void delete_at_position(struct node **head, int pos)
{
    if (*head == NULL || pos <= 0) {
        printf("Invalid position or empty list.\n");
        return;
    }

    struct node *temp = *head;

    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

   
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }

    
    if (temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    struct node *loc = temp->next;
    temp->next = loc->next;
    free(loc);
}

  void deleteValue(struct node **head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void printlist(struct node *head){
    struct node *temp =head;
    while (temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
     struct node* head = NULL;
    int choice, data, loc, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Linked List of n nodes\n");
        printf("2. Delete at Beginning\n");
        printf("3. Delete at End\n");
        printf("4. Delete at Position\n");
        printf("5. Delete by Value\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

switch(choice){
    case 1:
    printf("Enter number of nodes:");
    scanf("%d",&n);
    createlist(&head,n);
    break;
    case 2:
   delete_atbeg(&head);
    break;
    case 3:
    delete_at_end(&head);
    break;
    case 4 :
    printf("Enter position:");
    scanf("%d",&loc);
    delete_at_position(&head,loc);
    break;
    case 5:
    printf("Enter value to delete:");
    scanf("%d",&data);
    deleteValue(&head,data);
    break;
    case 6:
    printlist(head);
    break;
    case 7:
    exit(0);
    default :
    printf("plesse choose from 1 to 7\n");
}
    }
    return 0;
}