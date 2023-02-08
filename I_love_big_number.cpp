/*
    Keyword: Big number
    source1(answer): https://knightzone.studio/2015/05/11/2759/uva%EF%BC%9A10220%EF%BC%8Di-love-big-numbers/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    int mem[1005] = {1,1};
    int num[3000] = {1}, digits = 1;
    for(int i = 2; i <= 1000; i++) {
        for(int j = 0; j < digits; j++)
            num[j]*=i;
        for(int j = 0; j < digits; j++) {
            num[j+1] += num[j] / 10;
            if(j + 1 >= digits && num[j+1] > 0)++digits;
            num[j] %= 10;
            mem[i] += num[j];
        }
    }
    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", mem[n]);
    }
    return 0;
}