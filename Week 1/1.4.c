#include <stdio.h>

int getset(int[]);

int main()
{

    int data, num;

    num = getset(&data);

    return 0;
}

int getset(int[])
{

    int data;

    printf("Press number? : ");

    scanf("%d", &data);

    int arr[data];

    for (int i = 0; i < data; i++)
    {

        printf("Enter num %d: ", i + 1);

        scanf("%d", &arr[i]);
    }

    printf("You entered:\n");

    for (int i = 0; i < data; i++)
    {

        printf("number %d: %d\n", i + 1, arr[i]);
    }

    return data;
}