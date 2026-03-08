#include <stdio.h>

int *KnapsackDP(int *w, int *v, int n, int wx);

int main()
{

    int n = 5, wx = 11;

    int w[5] = {1, 2, 5, 6, 7};

    int v[5] = {1, 6, 18, 22, 28};

    int *x;

    x = KnapsackDP(w, v, n, wx);

    for (int i = 0; i < n; i++)
    {

        printf("%d ", x[i]);

    } // end for

    delete[] x;

    return 0;

} // end main

int *KnapsackDP(int *w, int *v, int n, int wx)
{

    int **K = new int *[n + 1];

    for (int i = 0; i <= n; i++)
    {

        K[i] = new int[wx + 1];

    } // end for

    for (int i = 0; i <= n; i++)
    {

        for (int w_idx = 0; w_idx <= wx; w_idx++)
        {

            if (i == 0 || w_idx == 0)
            {

                K[i][w_idx] = 0;
            }
            else if (w[i - 1] <= w_idx)
            {

                int a = K[i - 1][w_idx];

                int b = v[i - 1] + K[i - 1][w_idx - w[i - 1]];

                if (a > b)
                {

                    K[i][w_idx] = a;
                }
                else
                {

                    K[i][w_idx] = b;

                } // end if
            }
            else
            {

                K[i][w_idx] = K[i - 1][w_idx];

            } // end if

        } // end for

    } // end for

    int *x = new int[n];

    for (int i = 0; i < n; i++)
    {

        x[i] = 0;

    } // end for

    int res = K[n][wx];

    int curr_w = wx;

    for (int i = n; i > 0 && res > 0; i--)
    {

        if (res == K[i - 1][curr_w])
        {

            continue;
        }
        else
        {

            x[i - 1] = 1;

            res = res - v[i - 1];

            curr_w = curr_w - w[i - 1];

        } // end if

    } // end for

    for (int i = 0; i <= n; i++)
    {

        delete[] K[i];

    } // end for

    delete[] K;

    return x;

} // end KnapsackDP