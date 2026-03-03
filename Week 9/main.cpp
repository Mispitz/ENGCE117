#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};//end struct studentNode

class LinkedList {
protected:
    struct studentNode *start, **now;
public:
    LinkedList() {
        start = NULL;
        now = &start;
    }//end LinkedList

    ~LinkedList() {
        struct studentNode *temp;
        while (start != NULL) {
            temp = start;
            start = start->next;
            delete temp;
        }//end while
    }//end ~LinkedList

    void InsNode(const char name[], int age, char sex, float gpa) {
        struct studentNode *newNode = new studentNode;
        strcpy(newNode->name, name);
        newNode->age = age;
        newNode->sex = sex;
        newNode->gpa = gpa;

        newNode->next = *now;
        *now = newNode;
    }//end InsNode

    void DelNode() {
        if (*now != NULL) {
            struct studentNode *temp = *now;
            *now = (*now)->next;
            delete temp;
        }//end if
    }//end DelNode

    void GoNext() {
        if (*now != NULL) {
            now = &((*now)->next);
        }//end if
    }//end GoNext

    void GoFirst() {
        now = &start;
    }//end GoFirst

    void GoLast() {
        GoFirst();
        while (*now != NULL) {
            now = &((*now)->next);
        }//end while
    }//end GoLast

    void ShowAll() {
        struct studentNode *temp = start;
        printf("\n--- Student List ---\n");
        while (temp != NULL) {
            printf("%s %d %c %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
            temp = temp->next;
        }//end while
        printf("--------------------\n");
    }// end ShowAll

    int FindNode(char n[]) {
        GoFirst();
        while (*now != NULL) {
            if (strcmp((*now)->name, n) == 0) return 1;
            GoNext();
        }//end while
        return 0;
    }//end FindNode

    struct studentNode *NowNode() {
        return *now;
    }//end NowNode

    void EditNode(const char name[], int age, char sex, float gpa) {
        if (*now != NULL) {
            strcpy((*now)->name, name);
            (*now)->age = age;
            (*now)->sex = sex;
            (*now)->gpa = gpa;
        }//end if
    }//end EditNode
};// end LinkedList class

void EditData(LinkedList *ll) {
    char name[20] ;
    char newN[20] ;
    char sex;
    int age;
    float gpa;
    printf("Enter Name to find: ");
    scanf("%s", name);
    if (ll->FindNode(name)) {
        printf("Enter New Name, Age, Sex, GPA: ");
        scanf("%s %d %c %f", newN, &age, &sex, &gpa);
        ll->EditNode(newN, age, sex, gpa);
    } else {
        printf("Not found.\n");
    }// end if else
}// end EditData function

void AddData(LinkedList *ll) {
    char name[20];
    char sex;
    int age;
    float gpa;

    printf("Name: "); scanf("%s", name);
    printf("Age: ");  scanf("%d", &age);
    printf("Sex: ");  scanf(" %c", &sex);
    printf("GPA: ");  scanf("%f", &gpa);

    ll->GoLast();
    ll->InsNode(name, age, sex, gpa);
}// end AddData function

void FindData(LinkedList *ll) {
    char n[20];
    printf("Name to find: ");
    scanf("%s", n);

    if (ll->FindNode(n) == 1) {
        struct studentNode *curr = ll->NowNode();
        printf("Found: %s %d %c %.2f\n", curr->name, curr->age, curr->sex, curr->gpa);
    } else {
        printf("Not found\n");
    }// end if else
}// end FindData function

void readfile(LinkedList *ll) {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) return;
    char name[20];
    char sex;
    int age;
    float gpa;
    while (fscanf(fp, "%s %d %c %f", name, &age, &sex, &gpa) != EOF) {
        ll->GoLast();
        ll->InsNode(name, age, sex, gpa);
    }// end while
    fclose(fp);
}// end readfile function

void writefile(LinkedList *ll) {
    FILE *fp = fopen("data.txt", "w");
    if (fp == NULL) return; // end if
    ll->GoFirst();
    while (ll->NowNode() != NULL) {
        struct studentNode *curr = ll->NowNode();
        fprintf(fp, "%s %d %c %.2f\n", curr->name, curr->age, curr->sex, curr->gpa);
        ll->GoNext();
    }// end while
    fclose(fp);
}// end writefile function

int main() {
    LinkedList listA;
    int menu;
    readfile(&listA);

    do {
        printf("\nMenu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit: ");
        if (scanf("%d", &menu) != 1) break;

        switch (menu) {
            case 1: AddData(&listA); break;
            case 2: EditData(&listA); break;
            case 3: 
                char name[20];
                printf("Name to delete: ");
                scanf("%s", name);
                if (listA.FindNode(name)) listA.DelNode();
                else printf("Not found.\n");
                break;
            case 4: FindData(&listA); break;
            case 5: listA.ShowAll(); break;
        }
    } while (menu != 0); // end do while

    writefile(&listA);
    return 0;
}// end main function