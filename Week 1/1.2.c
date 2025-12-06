#include <stdio.h>

void GetSet( int ** , int * ) ;

int main() {
    int *data, num ;
    GetSet( &data, &num ) ;

    for ( int i = 0 ; i < num ; i++ ) {
        printf("%d\n",data[i]);
    }
    if (data != NULL) {
        free(data);
    }

    return 0 ;
}

void GetSet( int **data , int *num ) {
    if ( scanf( "%d" , num ) != 1 ) {
        printf( "Error" ) ;
        return ;
    }

    if ( *num <= 0 ) {
        printf( "Error" ) ;
        return ;
    }

        int i = 0 ;
        int *arr ;
        arr = malloc((size_t)(*num) * sizeof(int));
        if (arr == NULL) {
            printf("Error: memory allocation failed\n");
            *data = NULL;
            return;
        }

    for ( i = 0 ; i < *num ; i++ ) {
        if ( scanf( "%d" , &arr[ i ] ) != 1 ) {
            arr[ i ] = 0 ;
        }
    }

    *data = arr ;
}