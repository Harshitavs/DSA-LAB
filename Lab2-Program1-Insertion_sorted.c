#include <stdio.h>
#include <stdlib.h> 
#include<time.h>

int main() {
    int A[100000], size ,i,key,j;
    clock_t start , end;
    double time_taken;
    printf("Enter size of array");
    scanf("%d",&size);
    if (size>= 100000){
        printf("Size too large,");
        return 1;
    }
    

    // best case 
    for (i=0;i<size;i++)
    {
        A[i]=i;
    }
    start = clock();
for (i = 1; i < size  - 1; i++) {
         key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
 end = clock();
      time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Best Case Time = %f seconds\n", time_taken);
   
    // worst case   
    for (i = 0; i < size; i++) {
        A[i] = size - i;
    }

     start = clock();
    for (i = 1; i < size; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
    end = clock();
     time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nWorst Case Time = %f seconds\n", time_taken);

    srand(time(0));
   printf("Generating  array:\n");
for(i=0;i<size;i++) {
     A[i] = rand() % 1000;
}
printf("First 20 elements of random array:\n");
for (i = 0; i < size && i < 20; i++) {
    printf("%d ", A[i]);
}
printf("\n");
start = clock();
    for (i = 1; i < size; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;

    }
     

 end = clock();
    time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Average Case Time = %f seconds\n", time_taken);

    return 0;
}

  