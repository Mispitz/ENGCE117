#include <stdio.h>

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x);

int main()
{

    int n = 5, wx = 11;

    int w[5] = {1, 2, 5, 6, 7};

    int v[5] = {1, 6, 18, 22, 28};

    int *x, vx;

    x = new int[n];

    vx = KnapsackBT(w, v, n, wx, 0, x);

    printf("Value = %d\n", vx);

    for (int i = 0; i < n; i++)
    {

        printf("%d ", x[i]);

    } // end for

    delete[] x;

    return 0;

} // end main

int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x)
{

    int b = 0;

    int a = 0;

    int *y = new int[n];

    for (int j = 0; j < n; j++)
    {

        x[j] = 0;

    } // end for

    for (int k = i; k < n; k++)
    {

        if (w[k] <= wx)
        {

            for (int j = 0; j < n; j++)
            {

                y[j] = 0;

            } // end for

            a = v[k] + KnapsackBT(w, v, n, wx - w[k], k + 1, y);

            if (a > b)
            {

                b = a;

                for (int j = 0; j < n; j++)
                {

                    x[j] = y[j];

                } // end for

                x[k] = 1;

            } // end if

        } // end if

    } // end for

    delete[] y;

    return b;

} // end KnapsackBT