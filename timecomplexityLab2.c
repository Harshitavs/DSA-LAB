#include<stdio.h>  //
#include<time.h>
void printUPES(int n) {
    int i , j, k;
    for(i=1;i<=n;i++){
    for(j=1;j<=i;j++){
        for(k=1;k<=100;k++){
            printf("UPES");
        }
        }
        }
    }
int main(){
int n;
printf("Enter n:");
scanf("%d",&n);

clock_t start = clock();
printUPES(n);
        clock_t end = clock();
        double time_taken = (double)(end - start)/CLOCKS_PER_SEC ;
        printf("Time taken is %f seconds\n",time_taken);
        return 0;
    }