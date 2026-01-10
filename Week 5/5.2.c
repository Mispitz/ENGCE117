#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {

    char name[20];

    int age;

    float gpa;

    char sex;

    struct student *next;

} typedef stnode;


void showAll(stnode **walk);

void InsNode(stnode **now, char name[], int age, char sex, float gpa);

void DelNode(stnode **now);

void Gonext(stnode ***now);

int main() {

    stnode *start, **now;

    start = NULL; 

    now = &start; 
    
    InsNode(now, "one", 6, 'm', 3.11); showAll(&start);

    InsNode(now, "two", 8, 'f', 3.22); showAll(&start);

    Gonext(&now); 

    InsNode(now, "three", 10, 'm', 3.33); showAll(&start);

    InsNode(now, "four", 12, 'f', 3.44); showAll(&start);

    Gonext(&now);

    DelNode(now); showAll(&start); 

    return 0;
}

void showAll(stnode **walk) {
    
    stnode *temp = *walk; 

    while (temp != NULL) {

        printf("%s ", temp->name);

        temp = temp->next;

    }

    printf("\n");
}


stnode* Addnode(stnode **start, char name[], int age, char sex, float gpa) {
    
    stnode *newnode = (stnode*)malloc(sizeof(stnode));
    
    strcpy(newnode->name, name);
    
    newnode->age = age;

    newnode->sex = sex;

    newnode->gpa = gpa;

    newnode->next = *start;

    *start = newnode;

    return newnode;
}


void InsNode(stnode **now, char name[], int age, char sex, float gpa) {
   
    stnode *newnode;
    
    newnode = (stnode*)malloc(sizeof(stnode));

    strcpy(newnode->name, name);

    newnode->age = age;

    newnode->sex = sex;

    newnode->gpa = gpa;

    newnode->next = *now; 

    *now = newnode; 
}

void DelNode(stnode **now) {

    stnode *temp;
    
    if (*now == NULL) return; 

    temp = *now;      
     
    *now = temp->next; 
    
    free(temp);        
}

void Gonext(stnode ***now) {
    
    if ((**now) != NULL) {
        
        *now = &((**now)->next);
    }
}