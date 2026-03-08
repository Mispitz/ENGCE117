#include <stdio.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx ) ;

int main(){
    int n = 5 ;
    int i = 0 ;
    int wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x ;
    x = KnapsackGreedy( w, v, n, wx ) ;
    for( i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
} 

int *KnapsackGreedy( int *w, int *v, int n, int wx ) {
    int *x = new int[ n ] ;
    int *used = new int[ n ]() ;
    int weight = 0 ;
    int count = 0 ;
    int i, j ;

    for ( i = 0 ; i < n ; i++ ) {
        x[ i ] = 0 ;
    }

    while ( weight < wx && count < n ) {
        int best_i = -1 ;
        double max_ratio = -1.0 ;

        for ( j = 0 ; j < n ; j++ ) {
            if ( used[ j ] == 0 ) {
                double ratio = ( double ) v[ j ] / w[ j ] ;
                if ( ratio > max_ratio ) {
                    max_ratio = ratio ;
                    best_i = j ;
                } 
            } 
        } 

        if ( best_i != -1 ) {
            if ( weight + w[ best_i ] <= wx ) {
                x[ best_i ] = 1 ;
                weight = weight + w[ best_i ] ;
            } // end if
            used[ best_i ] = 1 ;
            count++ ;
        } else {
            break ;
        } // end if else
    } // end while loop

    delete[] used ;
    return x ;
} // end KnapsackGreedy function