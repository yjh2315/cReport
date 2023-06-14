#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
    int cons = 1234;
    int num = 4;
    // 난수의 자릿수
    int k = 1;
    int res = 0;
    int temp = 0;
    int rand = 2114;

    temp = cons*rand;
    for (int i=0; i<num; i++){
        k *= 10;
    }

    res = temp % k;

    printf("%d", res);
}