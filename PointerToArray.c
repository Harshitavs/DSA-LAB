#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    int A[n];  
    int *ptr = A;  
    printf("\nEnter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i);
        scanf("%d", &A[i]);
    }
    printf("\nArray elements and their addresses:\n");
    for (int i = 0; i < n; i++) {
        printf("A[%d] = %d, Address = %p\n", i, *(ptr + i), (ptr + i));
    }

    int index;
    printf("\nEnter index to see its address: ");
    scanf("%d", &index);

    if (index >= 0 && index < n) {
        printf("Address of A[%d] = %p\n", index, &A[index]);
    } else {
        printf("Invalid index!\n");
    }

    return 0;
}