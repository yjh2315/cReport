#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct point{
    int x;
    int y;
};

int main(){
    struct point points[10]={{0,0},};
    for(int i=0;i<10;i++){
        scanf("%d,%d",&points[i].x,&points[i].y);
        printf("(%d,%d)\n",points[i].x,points[i].y);
        int cnt = 0;
        for(int j=0;j<i;j++){
            if(points[j].x==points[i].x && points[j].y==points[i].y){
                cnt++;
            }
        }
        if(cnt!=0){
            printf("point(%d,%d)가 %d회 중복되었습니다.\n",points[i].x,points[i].y,cnt+1);
        }
    }
}