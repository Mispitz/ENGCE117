#include <stdio.h>

int *GetSet(int *);

#define MAX_ARRAY_SIZE 1000

int main()
{
    int *data, num;
    data = GetSet(&num);

    if (data == NULL)
    {
        return 1;
    }

    for (int i = 0; i < num; ++i)
    {
        printf("%d\n", data[i]);
    }
    return 0;
}

int *GetSet(int *num)
{

    if (scanf("%d", num) != 1)
    {
        printf("Array size input error\n");
        return NULL;
    }

    if (*num <= 0)
    {
        printf("Array size must be positive number\n");
        return NULL;
    }

    static int arr[MAX_ARRAY_SIZE];

    if (*num > MAX_ARRAY_SIZE)
    {
        printf("Array size exceeds maximum (%d)\n", MAX_ARRAY_SIZE);
        return NULL;
    }

    int i = 0;
    for (i = 0; i < *num; i++)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            printf("Array element input error\n");
            return NULL;
        }
    }

    return arr;
}