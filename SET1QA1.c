#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void insert_end( struct node** head , int data)
{
    struct node* newnode = createnode(data);
    if (*head == NULL){
        *head = newnode;
    return;
}
    struct node* temp = *head;
    while (temp->next != NULL)
    
        temp = temp->next;

        temp->next = newnode;
    }


void create_cycle(struct node* head, int pos)
{
    if (pos == -1)
        return;

    struct node* temp = head;
    struct node* cyclenode = NULL;
    int index = 0;
    while (temp->next != NULL)
    {
        if (index == pos)
            cyclenode = temp;
        temp = temp->next;
        index++;
    }
    temp->next = cyclenode;
}

bool Detect_removeloop(struct node* head)
{
    if (head == NULL || head->next == NULL)
        return false;

    struct node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {

            slow = head;

            if (slow == fast)
            {
                while (fast->next != slow)
                    fast = fast->next;
            }
            else
            {
                while (slow->next != fast->next)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
            }
            fast->next = NULL;
            return true;
        }
    }

    return false;
}
void printList(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp-> next;
    }
    printf("NULL\n");
}

int main()
{
    struct node* head = NULL;
    int n, data, pos;
    printf("Enter no of nodes:");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        insert_end(&head, data);
    }
    printf(" Enter position to createcycle (-1 for no cylce):");
    scanf("%d", &pos);

    create_cycle(head, pos);

    if (Detect_removeloop(head))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n ");
    }
    printf("List after removal of cycle:\n");
    printList(head);
    return 0;
}