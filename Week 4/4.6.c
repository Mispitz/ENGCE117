#include <stdio.h>

#include <string.h>

struct studentnode {

    char name[20];

    int age;

    char sex;

    float gpa;

    struct studentnode *next;

};

void savenode(struct studentnode *child, char n[], int a, char s, float g);

void GoNext2(struct studentnode **walk);

int main() {

    struct studentnode *start, *now1, **now2;

    start = new struct studentnode;

    savenode(start, "one", 6, 'm', 3.11);

    start->next = new struct studentnode;

    savenode(start->next, "two", 8, 'f', 3.22);

    start->next->next = new struct studentnode;

    savenode(start->next->next, "three", 10, 'm', 3.33);

    start->next->next->next = new struct studentnode;

    savenode(start->next->next->next, "four", 12, 'f', 3.44);

    now1 = start;

    now2 = &start;

    GoNext2(now2);

    printf("In Main: %s\n", (*now2)->name);

    return 0;

}

void savenode(struct studentnode *child, char n[], int a, char s, float g) {

    strcpy(child->name, n);

    child->age = a;

    child->sex = s;

    child->gpa = g;

    child->next = NULL;

}

void GoNext2(struct studentnode **walk) {

    if ((*walk)->next != NULL) {

        
        *walk = (*walk)->next;

        printf("%s\n", (*walk)->name); 
    }

}