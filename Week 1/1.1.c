#include <stdio.h>

int main (){
    int n;

    printf("Enter a number : ");
    scanf("%d", &n);

    char M[] = "Hello world";
    char *p =M;

    for(int i = 0 ; i < n ; i++) {
        printf("[%d]%s\n", i, p);
    }
    return 0;
}