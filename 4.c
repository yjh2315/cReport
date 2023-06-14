#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int student[1000] = {0,};
    int scoreNum[9] = {0,};

    srand(time(NULL));
    for(int i=0;i<1000;i++){
        student[i] = rand()%100+1;
        int temp = student[i];
        // printf("%d\t",temp);

        if(temp>=95){
            scoreNum[0]++;
        }else if(temp>=90){
            scoreNum[1]++;
        }else if(temp>=85){
            scoreNum[2]++;
        }else if(temp>=80){
            scoreNum[3]++;
        }else if(temp>=75){
            scoreNum[4]++;
        }else if(temp>=70){
            scoreNum[5]++;
        }else if(temp>=65){
            scoreNum[6]++;
        }else if(temp>=60){
            scoreNum[7]++;
        }else{
            scoreNum[8]++;
        }
    }
    int tScore = 0;
    for(int i=0;i<1000;i++){
        tScore+=student[i];
    }
    printf("\n\nn=1000 평균 = %d\n", tScore/1000);

    
    printf("A+ :%6d (%5.2f%)\n",scoreNum[0], (float)scoreNum[0]/10);
    printf("A  :%6d (%5.2f%)\n",scoreNum[1], (float)scoreNum[1]/10);
    printf("B+ :%6d (%5.2f%)\n",scoreNum[2], (float)scoreNum[2]/10);
    printf("B  :%6d (%5.2f%)\n",scoreNum[3], (float)scoreNum[3]/10);
    printf("C+ :%6d (%5.2f%)\n",scoreNum[4], (float)scoreNum[4]/10);
    printf("C  :%6d (%5.2f%)\n",scoreNum[5], (float)scoreNum[5]/10);
    printf("D+ :%6d (%5.2f%)\n",scoreNum[6], (float)scoreNum[6]/10);
    printf("D  :%6d (%5.2f%)\n",scoreNum[7], (float)scoreNum[7]/10);
    printf("F  :%6d (%5.2f%)\n",scoreNum[8], (float)scoreNum[8]/10);
}