#include <stdio.h>


struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};


struct student (*GetStudent(int *room))[10];

int main() {
    
    struct student (*children)[10]; 

    int group;

    
    children = GetStudent(&group);


    return 0;
}


struct student (*GetStudent(int *room))[10] {
    
    static struct student child[20][10]; 

    printf("Enter number of classrooms: ");

    scanf("%d", room); 

    for (int i = 0; i < *room; i++) {

        printf("--- Room %d ---\n", i + 1);

        for (int j = 0; j < 10; j++) {

            printf("Student %d Name: ", j + 1);

            scanf("%s", child[i][j].name);

            printf("Student %d Age: ", j + 1);

            scanf("%d", &child[i][j].age);
            
            
        }
    }

    
    return child;
}