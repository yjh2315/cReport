#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cons = 1234;
    int num = 4;
    // 난수의 자릿수
    int k = 1;
    int res = 0;
    int temp = 0;
    int random = 4321;
    // #include <time.h>
    // srand(time(NULL));
    // rand = rand();
    // 을 통해 난수를 임의로 지정하는 것이 아닌 랜덤값으로 받아올 수 있습니다.
    // 해당 식은 결과를 비교하기 위해 상수값을 대입했습니다.

    for (int rep = 0; rep < 10; rep++)
    {
        temp = cons * random;
        k = 1;
        for (int i = 0; i < num; i++)
        {
            k *= 10;
        }

        res = temp % k;
        random = res;

        printf("%04d\n", res);
    }
}