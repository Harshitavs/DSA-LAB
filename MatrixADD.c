#include<stdio.h>

 void addMatrices(int rows, int cols, int M1[rows][cols], int M2[rows][cols], int sum[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = M1[i][j] + M2[i][j];
        }
    }
}


/*
void subtractMatrices(int rows, int cols, int M1[rows][cols], int M2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = M1[i][j] - M2[i][j];
        }
    }
}
*/
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
int main (){
    int rows1,cols1 , rows2 , cols2;

    printf("Enter number of rows for first matrix:");
    scanf("%d",&rows1);
    printf("Enter number of columns for first matrix:");
    scanf("%d",&cols1);
    printf("Enter number of rows for second matrix:");
    scanf("%d",&rows2);
    printf("Enter number of columns for second matrix:");
    scanf("%d",&cols2);

     
    if (rows1 <= 0 || cols1 <= 0 || rows2 <= 0 || cols2 <= 0) {
        printf("Invalid matrix size! Rows and columns must be positive.\n");
        return 0;
    }

    int M1[rows1][cols1] , M2[rows2][cols2],sum[rows1][cols1]; 
    int result[rows1][cols1];

    printf("Enter elements of first matrix:\n");
    for(int i=0;i<rows1;i++){
        for(int j=0;j<cols1;j++){
            printf("Element [%d][%d]:",i+1,j+1 ) ;
            scanf("%d",&M1[i][j]);

        }

    }
    printf("Enter elements of second matrix.\n");
    for(int i=0;i<rows2;i++){
        for(int j=0;j<cols2;j++){
            printf("Element [%d][%d]: " ,i+1,j+1);
            scanf("%d",&M2[i][j]);
        }
    }

    if (rows1 != rows2 || cols1 != cols2) {
        printf("\nError: Matrices must have the same size for addition or subtraction!\n");
        return 0;
    }


   addMatrices(rows1, cols1,M1,M2,sum);

   // subtractMatrices(rows, cols,M1,M2,result);


    printf("\nFirst Matrix:\n");
    printMatrix(rows1, cols1, M1);

    printf("\nSecond Matrix:\n");
    printMatrix(rows2, cols2, M2);

    printf("\nSum of the two matrices:\n");
    printMatrix(rows1, cols1, sum);
   // printf("\nDifference of two matrix:\n");
   // printMatrix(rows,cols,result);
}