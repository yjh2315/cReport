#include <stdio.h>
#include <stdlib.h>

int makeValue(int in)
{
	int pValue = in;
	int tempValue = 0;

	tempValue = pValue * pValue;
	int lenTemp = tempValue;
	int len = 0;

	while (lenTemp > 0)
	{
		lenTemp /= 10;
		len++;
	}

	int rightLen = len - 4 - ((len - 4) / 2);
	// int leftLen = (lenTemp - 4) / 2;

	for (int i = 0; i < rightLen; i++)
	{
		tempValue /= 10;
	}

	tempValue %= 10000;

	return tempValue;
}

int main()
{
	int firstIn = 1234;
	int val = makeValue(firstIn);
	if (val / 1000 == 0)
	{
		printf("0");
	}
	printf("%d\n", val);

	for (int i = 0; i < 10; i++)
	{
		val = makeValue(val);
		if (val / 1000 == 0)
		{
			printf("0");
		}
		printf("%d\n", val);
	}
}