#include <stdio.h>

void mergesort( int t[], int k ) ;
void merge( int *u, int m, int *v, int n, int *t ) ;

int main() {
    int data[ 7 ] = { 4, 6, 1, 2, 5, 1, 8 } ;
    int n = 7 ;
    mergesort( data, n ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d " , data[ i ] ) ;

    return 0 ;
}// end main function

void mergesort( int t[], int k ) {
    if( k > 1 ) {
        int mid = k / 2 ;
        int n = k - mid ;
        
        int u[ mid ] ;
        int v[ n ] ;

        int i = 0 ;

        for( i = 0 ; i < mid ; i++ ) {
            u[ i ] = t[ i ] ;
        }// end for loop

        for( i = mid ; i < k ; i++ ) {
            v[ i - mid ] = t[ i ] ;
        }// end for loop

        mergesort( u , mid ) ;
        mergesort( v , n ) ;
        merge( u, mid, v, n, t ) ;
    }// end if
}// end mergesort function

void merge( int *u, int m, int *v, int n, int *t ) {
    int i = 0 ;
    int j = 0 ;
    int k = 0 ;

    for( k = 0 ; k < m + n ; k++ ) {
        if( i >= m ) {
            t[ k ] = v[ j ] ;
            j++ ;
        }
        else if( j >= n ) {
            t[ k ] = u[ i ]  ;
            i++ ;
        }
        else if( u[ i ] < v[ j ] ) {
            t[ k ] = u[ i ] ;
            i++ ;
        }
        else {
            t[ k ] = v[ j ] ;
            j++ ;
        }// end if else
    }// end for loop
}//end merge function