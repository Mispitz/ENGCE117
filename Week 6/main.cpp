#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20

struct studentNode {
    char name[ NAME_SIZE ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
    struct studentNode *back ;
};

void ShowAll( struct studentNode *walk ) ;
void GoBack( struct studentNode *walk ) ;
struct studentNode *AddNode( struct studentNode **walk , const char name[ NAME_SIZE ] , int age , char sex , float gpa ) ;
void InsNode( struct studentNode *walk , struct studentNode **begin , const char name[ NAME_SIZE ] , int age , char sex , float gpa ) ;
void DelNode( struct studentNode **walk , struct studentNode **begin ) ;

int main() {
    struct studentNode *start, *now ;
    start = NULL ;
    now = AddNode( &start, "one", 6, 'M', 3.11 ) ; 
    ShowAll( start ) ;
    now = AddNode( &start, "two", 8, 'F', 3.22 ) ; 
    ShowAll( start ) ;
    InsNode( now, &start , "three", 10, 'M', 3.33 ) ; 
    ShowAll( start ) ;
    InsNode( now, &start , "four", 12, 'F', 3.44 ) ; 
    ShowAll( start ) ;
    GoBack( now ) ;
    DelNode( &now , &start ) ; 
    ShowAll( start ) ;
    DelNode( &now , &start ) ; 
    ShowAll( start ) ;
    DelNode( &now , &start ) ;  
    ShowAll( start ) ;

    delete start , *now ;
    return 0;
} // end int main function

void ShowAll( struct studentNode *walk ) {
    while( walk != NULL ) {
        printf( "%s " , walk->name ) ;
        walk = walk->next ;
    }// end while loop
    printf( "\n" ) ;
}// end void ShowAll function

void GoBack( struct studentNode *walk ) {
    while( walk != NULL ) {
        printf( "%s " , walk->name ) ;
        walk = walk->back ;
    }// end while loop
    printf( "\n" ) ;
}// end void ShowAll function

struct studentNode *AddNode( struct studentNode **walk , const char name[ NAME_SIZE ] , int age , char sex , float gpa ) {

    struct studentNode *temp = NULL ;

    while( *walk != NULL ) {
        temp = *walk ;
        walk = &( *walk )->next ;
    }// end while loop

    *walk = new struct studentNode ;
    strcpy( ( *walk )->name , name ) ;
    ( *walk )->age = age ;
    ( *walk )->sex = sex ;
    ( *walk )->gpa = gpa ;
    ( *walk )->next = NULL ;
    ( *walk )->back = temp ;

    delete temp ;

    return *walk ;
}// end struct studentNode *AddNode function

void InsNode( struct studentNode *walk , struct studentNode **begin , const char name[ NAME_SIZE ] , int age , char sex , float gpa ) {
    if ( walk->back != NULL ) {
        walk->back->next = new struct studentNode ;
        strcpy( ( walk )->back->next->name , name ) ;
        walk->back->next->sex = sex ;
        walk->back->next->gpa = gpa ;
        walk->back->next->next = walk ;
        walk->back->next->back = walk->back ;
        walk->back = walk->back->next ;
    }
    else {
        walk->back->next = new struct studentNode ;
        strcpy( ( walk )->name , name ) ;
        ( *begin )->sex = sex ;
        ( *begin )->gpa = gpa ;
        ( *begin )->next = walk ;
        ( *begin )->back = NULL ;
        walk->back = *begin ;
    }// end if else

    delete walk , *begin ;
}// end void InsNode function

void DelNode( struct studentNode **walk , struct studentNode **begin ) {
    struct studentNode *temp ;

    if ( (*walk)->back != NULL ) {
        (*walk)->back->next = (*walk)->next ;
    }
    else {
        *begin = ( *walk )->next ;
    }// end if else

    if( ( *walk )->next != NULL ) {
        ( *walk )->next->back = ( *walk )->back ;
        temp = ( *walk )->next ;
    }
    else {
        temp = ( *walk )->back ;
    }// end if else
    delete *walk , *temp ;
    *walk = temp ;
}// end void DelNode function