
#include <stdio.h>

int getmatrix( int *row, int *col);

int main(){

    int *data, m, n;

    *data = getmatrix( &m, &n);

    return 0;
}

int getmatrix( int *row, int *col){

    printf("Enter number of rows: ");

    scanf("%d", row);

    printf("Enter number of columns: ");

    scanf("%d", col);

    int matrix[*row][*col];

    for (int i = 0; i < *row; i++) {

        for (int j = 0; j < *col; j++) {

            printf("Enter num [%d][%d]: ", i + 1, j + 1);

            scanf("%d", &matrix[i][j]);

        }

    }

    printf("You entered:\n");

    for (int i = 0; i < *row; i++) {

        for (int j = 0; j < *col; j++) {

            printf("%d ", matrix[i][j]);

        }

        printf("\n");

    }

    return 0;
}
