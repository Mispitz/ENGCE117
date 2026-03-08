#include <stdio.h>

long SumLoop( int ) ;
long SumRecur( int ) ;

int main() {
    printf( "SumLoop(n) = %d\n" , SumLoop(10) ) ;
    printf( "SumRecur(n) = %d" , SumRecur(10) ) ;
    return 0 ;
}

long SumLoop( int n ) {
    int i = 0 ;
    int sum = 0 ;

    for( i = 0 ; i < n ; i++ ) {
        sum += i + 1 ;
    }

    return sum ;
}

long SumRecur( int n ) {
    if ( n <= 0 ) return 0 ;
    return n + SumRecur( n - 1 ) ;
}
