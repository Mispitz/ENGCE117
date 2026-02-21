#include <stdio.h>
#include <stdlib.h>


struct studentNode {

    char name[ 20 ] ;

    int age ;

    char sex ;

    float gpa ;

    struct studentNode *next ; 

}typedef stnode;

class LinkedList {
    protected :

        stnode *start, **now ;

    public :

        LinkedList() ;

        ~LinkedList() ;

        void InsNode( char n[], int a, char s, float g ) ;

        void DelNode() ;

        void GoNext() ; 

        virtual void ShowNode() ;

} ;

class NewList : public LinkedList {

    public :

        void GoFirst() ; 

        virtual void ShowNode() ;

        void InsertNode( char n[], int a, char s, float g ) ; 

} ;

void processListA(LinkedList &listA) ;

void processListB(NewList &listB) ;

void processListC(LinkedList *&listC, LinkedList &listA, NewList &listB) ;



int main() {

    LinkedList listA ;

    NewList listB ;

    LinkedList *listC ;

    processListA(listA) ;

    processListB(listB) ;

    processListC(listC, listA, listB) ;

    return 0 ;
}

void processListA(LinkedList &listA) {

    listA.InsNode( "one", 1, 'A', 1.1 ) ;

    listA.InsNode( "two", 2, 'B', 2.2 ) ;

    listA.InsNode( "three", 3, 'C', 3.3 ) ;

    listA.GoNext() ;

    listA.ShowNode() ;

}

void processListB(NewList &listB) {

    listB.InsertNode( "four", 4, 'D', 4.4 ) ;

    listB.InsertNode( "five", 5, 'E', 5.5 ) ;

    listB.InsertNode( "six", 6, 'F', 6.6 ) ;

    listB.GoNext() ;

    listB.DelNode() ;

    listB.ShowNode() ;

}

void processListC(LinkedList *&listC, LinkedList &listA, NewList &listB) {

    listC = &listA;

    listC->GoNext() ;

    listC->ShowNode() ;

    listC = &listB;

    listC->ShowNode() ;
}

LinkedList::LinkedList() {

    start = NULL ;

    now = &start ; 
}

LinkedList::~LinkedList() {

    stnode *temp = start ;

    while (temp != NULL) {

        stnode *next = temp->next ;

        delete temp ;

        temp = next ;
    }
}

void LinkedList::InsNode( char n[], int a, char s, float g ) {

    stnode *newNode = new stnode ;

    sprintf(newNode->name, "%s", n) ; 

    newNode->age = a ;

    newNode->sex = s ;

    newNode->gpa = g ;
    
    newNode->next = start ;

    start = newNode ;
}

void LinkedList::DelNode() {

    if (*now != NULL) {

        stnode *temp = *now ;

        *now = temp->next ; 

        delete temp ;
    }
}

void LinkedList::GoNext() {

    if (*now != NULL) {

        now = &((*now)->next) ;

    }
}

void LinkedList::ShowNode() {

    if (*now != NULL) {

        printf("%s %d %c %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa) ;

    }
}

void NewList::GoFirst() {

    now = &start ;

}

void NewList::InsertNode( char n[], int a, char s, float g ) {

    InsNode(n, a, s, g) ; 

}

void NewList::ShowNode() {

    stnode *temp = start ;

    while (temp != NULL) {

        printf("%s", temp->name) ;

        if (temp->next != NULL) {

            printf(" ") ;

        }

        temp = temp->next ;
    }

    printf("\n") ;

}