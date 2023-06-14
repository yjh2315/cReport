#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sortArr(int (* in)[6]);

int main()
{
    srand(time(NULL));
    int getLotto[10][6] = {
        {
            0,
        },
    };

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int temp = rand() % 44 + 1;

            for (int k = 0; k < j; k++)
            {
                if (getLotto[i][k] == temp)
                {
                    temp = rand() % 44 + 1;
                    k = 0;
                    continue;
                }
            }
            getLotto[i][j] = temp;
        }
    }
    sortArr(&getLotto);
    for (int i = 0; i < 10; i++)
    {
        printf("%2d번째 복권번호는 : ", i + 1);
        for (int j = 0; j < 6; j++)
        {
            printf("%5d", getLotto[i][j]);
        }
        printf("\n");
    }
}

void sortArr(int(*in)[6])
{
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int a = 5; a > 0; a--)
        {
            for (int j = 0; j < a; j++)
            {
                if (in[i][j] > in[i][j + 1])
                {
                    temp = in[i][j];
                    in[i][j] = in[i][j + 1];
                    in[i][j + 1] = temp;
                }
            }
        }
    }
}
