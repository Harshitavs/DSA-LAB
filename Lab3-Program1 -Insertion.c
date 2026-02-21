#include <stdio.h>
#include <time.h>  

int insert_Beginning(int A[], int n, int max_size, int num) {
    if (n >= max_size) {
        printf("Overflow! Cannot add more elements\n");
        return n;
    }
    for (int i = n; i > 0; i--) {
        A[i] = A[i - 1];
    }
    A[0] = num;
    return n + 1;
}

int insert_atindex(int A[], int n, int pos, int max_size, int num) {
    if (n >= max_size) {
        printf("Overflow! Cannot enter more elements\n");
        return n;
    }
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return n;
    }
    for (int i = n; i >= pos; i--) {
        A[i] = A[i - 1];
    }
    A[pos - 1] = num;
    return n + 1;
}

int main() {
    int n, pos, num, max_size = 100;
    printf("Enter no of elements: ");
    scanf("%d", &n);

    if (n > max_size) {
        printf("Too many elements! Max size is %d\n", max_size);
        return 0;
    }

    int A[max_size];   
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter the position where to insert element: ");
    scanf("%d", &pos);
    printf("Enter element to be inserted: ");
    scanf("%d", &num);

  
    clock_t start = clock();

    if (pos == 1) {
        n = insert_Beginning(A, n, max_size, num);
    } else {
        n = insert_atindex(A, n, pos, max_size, num);
    }

    
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\nTime taken for insertion: %f seconds\n", time_taken);

    return 0;
}