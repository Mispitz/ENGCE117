#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void SaveNode( struct studentNode *child , char n[] , int a , char s , float g ) ;
void GoNext1( struct studentNode *walk ) ;

int main() {
    struct studentNode *start , *now1 , **now2 ;
    char text[ 50 ] ;

    start = new struct studentNode ;
    strcpy( text , "one" ) ;
    SaveNode( start , text , 6 , 'M' , 3.11 ) ;

    start->next = new struct studentNode ;
    strcpy( text , "two" ) ;
    SaveNode( start->next , text , 8 , 'F' , 3.22 ) ;

    start->next->next = new struct studentNode ;
    strcpy( text , "three" ) ;
    SaveNode( start->next->next , text , 10 , 'M' , 3.33 ) ;

    start->next->next->next = new struct studentNode ;
    strcpy( text , "four" ) ;
    SaveNode( start->next->next->next , text , 12 , 'F' , 3.44 ) ;

    now1 = start ;
    now2 = &start ;

    GoNext1( now1 ) ;
    printf( "%s" , now1->name ) ;

    return 0 ;
}// end main function

void SaveNode( struct studentNode *child , char n[] , int a , char s , float g ) {
    strcpy( child->name , n ) ;
    child->age = a ;
    child->sex = s ;
    child->gpa = g ;
}//end SaveNode function

void GoNext1( struct studentNode *walk ) {
    if ( walk == nullptr ) {
        return ;
    }// end if
    walk = walk->next ;
}//end GoNext1 function