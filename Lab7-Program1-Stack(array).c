#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

int isFull(){
    return (top == MAX-1);
}

int isEmpty () {
    return (top == -1);
}

void push(int value){
    if ( isfull()){
        printf("Stack Overflow\n");
    } else {
        stack[++top] = value;
    }
}
void pop(){
    if (isEmpty()){
        printf("Stack underflow\n");
    }else {
        printf("Deleted element :%d\n",stack[--top]);
    }
}
void display() {
    if (isEmpty()){
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        for (int i = top; i>= 0;i--){
            printf("%d\n", stack[i]);
        }
    }
}
int main (){
    int n , value;

    printf("Enter number of elemnt:");
    scanf("%d", &n);

    if (n > MAX){
        printf("Stack size exceeded! Max = %d\n", MAX);
        return 0;
    }

    for (int i =0;i<n;i++){
        printf("Enter element %d:" , i+1);
    scanf ("%d", &value);
    push(value);
    }

    display();

    pop();
    display();

    return 0;
}