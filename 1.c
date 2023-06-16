#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

int **makeArr(int **in, int x_range, int y_range);
int **mulArr(int **in1, int size1_x, int size1_y, int **in2, int size2_x, int size2_y);
void printArr(int **in, int x, int y);

int main()
{
    int **arrA;
    int **arrB;
    int **arrC;
    int a_X = 0, a_Y = 0, b_X = 0, b_Y = 0, c_X = 0, c_Y = 0;

    printf("배열의 크기를 입력해주세요.\ni : ");
    scanf("%d", &a_X);
    printf("j : ");
    scanf("%d", &a_Y);
    arrA = makeArr(arrA, a_X, a_Y);

    printf("\n배열의 크기를 입력해주세요.\ni : ");
    scanf("%d", &b_X);
    printf("j : ");
    scanf("%d", &b_Y);
    arrB = makeArr(arrB, b_X, b_Y);

    c_X = b_X;
    c_Y = a_Y;
    arrC = mulArr(arrA, a_X, a_Y, arrB, b_X, b_Y);
    printf("\n계산 결과 행렬:\n");
    printArr(arrC, c_X, c_Y);
    // 생성된 배열들로 결과 행렬을 출력합니다.

    for (int i = 0; i < a_X; i++)
    {
        free(arrA[i]);
    }
    free(arrA);
    for (int i = 0; i < b_X; i++)
    {
        free(arrB[i]);
    }
    free(arrB);
    for (int i = 0; i < c_X; i++)
    {
        free(arrC[i]);
    }
    free(arrC);
    return 0;
}

int **makeArr(int **in, int x_range, int y_range)
// x, y값만큼 동적할당하고, 입력받은 후 그 주소를 넘겨줍니다.
{
    int **tempArr = (int **)malloc(sizeof(int *) * x_range);
    for (int temp = 0; temp < x_range; temp++)
    {
        tempArr[temp] = (int *)malloc(sizeof(int) * y_range);
        for (int temp2 = 0; temp2 < y_range; temp2++)
        {
            tempArr[temp][temp2] = 0;
        }
    }

    for (int j = 0; j < y_range; j++)
    {
        for (int i = 0; i < x_range; i++)
        {
            scanf("%d", &tempArr[i][j]);
        }
    }
    return tempArr;
}

// 결과값 배열을 동적할당하여 생성하고, 그 값들을 각각 연산한 후 리턴합니다.
int **mulArr(int **in1, int size1_x, int size1_y, int **in2, int size2_x, int size2_y)
{
    int **tempArr = (int **)malloc(sizeof(int *) * size2_x);
    for (int temp = 0; temp < size2_x; temp++)
    {
        tempArr[temp] = malloc(sizeof(int) * size1_y);
    }

    for (int i = 0; i < size2_x; i++)
    {
        for (int j = 0; j < size1_y; j++)
        {
            int temp = 0;
            for (int x = 0; x < size1_x; x++)
            {
                temp += in1[x][j] * in2[i][x];
            }
            tempArr[i][j] = temp;
        }
    }

    return tempArr;
}

// arr을 출력합니다.
void printArr(int **in, int x, int y)
{
    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            printf("%d ", in[i][j]);
        }
        printf("\n");
    }
}