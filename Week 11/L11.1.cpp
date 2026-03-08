#include <stdio.h>

int BinSearch( int[], int, int ) ;

int main() {
    int data[ 6 ] = { 1, 2, 3, 4, 5, 7 } ;
    int n = 6 ;
    int find = 5 ;
    int pos = BinSearch( data, n, find ) ;

    printf( "Found %d at %d", find, pos ) ;

    return 0 ;
}// end main function

int BinSearch( int data[], int n, int find ) {
    int i = 0 ;
    int j = n - 1 ;
    int m ;
    int pos ;

    while( i < j ){
        m = ( i + j ) / 2 ;
        if( data[ m ] < find ) {
            i = m + 1 ;
        }
        else {
            j = m ;
        }// end if else
    }// end while

    if( data[ i ] == find ) {
        pos = i ;
    }
    else {
        pos = -1 ;
    }// end if else

    return pos ;
}// end BinSearch function