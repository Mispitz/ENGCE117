#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct student{

    char name[20];

    int age;

    float gpa;

    char sex;

    struct student *next;

}typedef stnode;

void showAll(stnode *walk);

stnode* Addnode(stnode **start, char name[], int age, char sex, float gpa);

void InsNode(stnode *now, char name[], int age, char sex, float gpa);

void DelNode(stnode *now);

int main(){

    stnode *start, *now;

    start = NULL;


    now = Addnode(&start, "one", 6, 'm', 3.11); 
    showAll(start);

  
    InsNode(now, "two", 8, 'f', 3.22); 
  
    now = now->next; 
    showAll(start);

    
    InsNode(now, "three", 10, 'm', 3.33); 
    showAll(start);

    
    InsNode(now, "four", 12, 'f', 3.44); 
    showAll(start);

    
    DelNode(now); 
    showAll(start);

    return 0;
}


void showAll(stnode *walk){

    while(walk != NULL){

        printf("%s ", walk->name); 

        walk = walk->next;

    }

    printf("\n");
}


stnode* Addnode(stnode **start, char name[], int age, char sex, float gpa){
    stnode *newnode;

    newnode = (stnode*)malloc(sizeof(stnode));

    strcpy(newnode->name, name);

    newnode->age = age;

    newnode->sex = sex; 

    newnode->gpa = gpa;

    newnode->next = *start;

    *start = newnode;

    return newnode;
}

void InsNode(stnode *now, char name[], int age, char sex, float gpa){
    
    stnode *newnode;

    newnode = (stnode*)malloc(sizeof(stnode));

    strcpy(newnode->name, name);

    newnode->age = age; 

    newnode->sex = sex;

    newnode->gpa = gpa; 

    newnode->next = now->next;

    now->next = newnode;
}

void DelNode(stnode *now){

    stnode *temp;
    
    if(now == NULL || now->next == NULL) return; 

    temp = now->next;

    now->next = temp->next;

    free(temp);
}