#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card
{
	char shape;
	int num;
};

int main()
{
	struct card deck[52];
	for (int i = 0; i < 52; i++)
	{
		int tempNum = i % 13 + 1;
		int tempShape = i / 13;

		switch (tempShape)
		{
		case 0:
			deck[i].shape = 'c';
			break;
		case 1:
			deck[i].shape = 'd';
			break;
		case 2:
			deck[i].shape = 'h';
			break;
		case 3:
			deck[i].shape = 's';
			break;
		}

		deck[i].num = tempNum;
	}

	for (int i = 0; i < 52; i++)
	{
		printf("%c.%d\t", deck[i].shape, deck[i].num);
	}

	printf("\n\n");

	struct card selDeck[7];
	srand(time(NULL));
	for (int i = 0; i < 7; i++)
	{
		/*scanf("%c.%d", &(selDeck[i].shape), &(selDeck[i].num));*/
		int tempShape;
		int tempNum;

		tempShape = rand() % 4;
		tempNum = rand() % 13 + 1;
		switch (tempShape)
		{
		case 0:
			tempShape = 'c';
			break;
		case 1:
			tempShape = 'd';
			break;
		case 2:
			tempShape = 'h';
			break;
		case 3:
			tempShape = 's';
			break;
		}
		if (i != 0)
		{
			char tempChk = 0;
			for (int j = 0; j < i; j++)
			{
				if (selDeck[j].shape == tempShape && selDeck[j].num == tempNum)
				{
					tempChk = 1;
					break;
				}
			}
			if (tempChk == 1)
			{
				i--;
				continue;
			}
		}

		selDeck[i].num = tempNum;
		selDeck[i].shape = tempShape;
	}

	for (int i = 0; i < 7; i++)
	{
		printf("%c.%d\t", selDeck[i].shape, selDeck[i].num);
	}
}