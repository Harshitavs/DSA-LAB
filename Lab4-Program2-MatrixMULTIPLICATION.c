#include<stdio.h>
void multiplyMatrix (int rows1, int cols1 , int M1[rows1][cols1],int rows2, int cols2 , int M2[rows2][cols2], int result[rows1][cols2] ){
    for (int i = 0;i<rows1;i++){
        for(int j = 0;j<cols2;j++){
            result[i][j] = 0;

        }
    }
    for(int i = 0;i<rows1;i++){
        for(int j= 0;j<cols2;j++){
            for(int k = 0;k<cols1;k++){
                result[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }
}

void printMatrix(int rows, int cols , int matrix[rows][cols]){
    for(int i =0; i<rows ; i++) {
        for(int j = 0; j<cols ;j++){
  printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int rows1 ,cols1 , rows2,cols2 ;
    printf("Enter rows  and columns for matrix 1:");
    scanf("%d %d" , &rows1 , &cols1);

    printf("Enter  rows and columns for matrix 2:");
    scanf("%d %d" , &rows2 , &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    int M1[rows1][cols1], M2[rows2][cols2], result[rows1][cols2];

    printf("Enter elements of Matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &M1[i][j]);
        }
    }

    printf("Enter elements of Matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &M2[i][j]);
        }
    }

     multiplyMatrix(rows1 ,cols1 , M1 , rows2, cols2 ,M2 , result );

    printf("Matrix Multiplication Result:\n");
    printMatrix(rows1, cols2, result);

    return 0;
}
