#include <stdio.h>

int *Dijkstra( int *L, int n ) ;

int main() {
    int n = 5 ;
    int i = 0 ;
    int j = 0 ;
    int *d ;
    int *g ;

    g = new int[ n * n ] ;

    for( i = 0 ; i < n ; i++ )
        for( j = 0 ; j < n ; j++ )
            g[ i * n + j ] = -1 ;

    g[ 0 * n + 1 ] = 100 ;
    g[ 0 * n + 2 ] = 80 ;
    g[ 0 * n + 3 ] = 30 ;
    g[ 0 * n + 4 ] = 10 ;
    g[ 1 * n + 2 ] = 20 ;
    g[ 3 * n + 1 ] = 20 ;
    g[ 3 * n + 2 ] = 20 ;
    g[ 4 * n + 3 ] = 10 ;

    d = Dijkstra( g, n ) ;
    for( i = 0 ; i < n - 1 ; i++ )
        printf( "%d ", d[ i ] ) ;

    return 0 ;
}// end main function

int *Dijkstra( int *L, int n ) {
    int *D_out = new int[ n - 1 ] ;
    int D[ n - 1 ] ;
    int C[ n - 1 ] ; 
    int i, count, v, w ;

    for( i = 1 ; i < n ; i++ ) {
        C[ i ] = 1 ; 
        D[ i ] = L[ 0 * n + i ] ;
    }//end for

    for( count = 0 ; count < n - 2 ; count++ ) {
        v = -1 ;
        for( i = 1 ; i < n ; i++ ) {
            if( C[ i ] == 1 && D[ i ] != -1 ) {
                if( v == -1 || D[ i ] < D[ v ] ) {
                    v = i ;
                }//end if
            }//end if
        }//end for loop

        if( v == -1 ) break ;
        C[ v ] = 0 ;

        for( w = 1 ; w < n ; w++ ) {
            if( C[ w ] == 1 ) {
                int edge = L[ v * n + w ] ;
                if( edge != -1 ) {
                    int dist = D[ v ] + edge ;
                    if( D[ w ] == -1 || dist < D[ w ] ) {
                        D[ w ] = dist ;
                    }//end if
                }//end if
            }//end if
        }//end for loop
    }//end for loop

    for( i = 0 ; i < n - 1 ; i++ ) {
        D_out[ i ] = D[ i + 1 ] ;
    }//end for loop

    return D_out ;
}//end Dijkstra function