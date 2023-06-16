#define _CRT_SECURE_NO_WARNINGS
#define SizeX 100
#define SizeY 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <windows.h>

struct mych
{
    char ch;
    int pos;
    int speed;
};

void resetScreen(char (*in)[SizeX][SizeY])
{
    for (int i = 0; i < SizeY; i++)
    {
        for (int j = 0; j < SizeX; j++)
        {
            (*in)[j][i] = ' ';
        }
    }
}

void printScreen(char (*in)[SizeX][SizeY])
{
    for (int i = 0; i < SizeY; i++)
    {
        for (int j = 0; j < SizeX; j++)
        {
            printf("%c", (*in)[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));
    struct mych listCh[26];
    char screen[SizeX][SizeY];
    char(*ptScreen)[SizeX][SizeY] = &screen;
    resetScreen(ptScreen);

    for (int i = 0; i < 26; i++)
    {
        int tempVal = rand() % (SizeX * SizeY);
        listCh[i].pos = tempVal;
        listCh[i].speed = rand() % 10 + 1;
        listCh[i].ch = i + 'A';

        screen[tempVal % SizeX][tempVal / SizeX] = i + 'A';
    }

    int i = 0;

    // 종료하려면 Ctrl + C
    while (1)
    {
        printScreen(ptScreen);
        resetScreen(ptScreen);
        printf("%d\n", i);
        Sleep(1000);
        i++;
        // system("cls");
        // windows 환경에서 해당 코드와 #include<windows.h> 사용시 화면 출력사항 다 지워줌.

        for (int i = 0; i < 26; i++)
        {
            listCh[i].pos += listCh[i].speed;
            int tempVal = listCh[i].pos % (SizeX * SizeY);
            listCh[i].pos = tempVal;
            listCh[i].ch = i + 'A';

            screen[tempVal % SizeX][tempVal / SizeX] = i + 'A';
        }
    }
}