/*
    Keyword: None
    source1(answer): https://knightzone.studio/2014/08/21/1969/uva%EF%BC%9A256%EF%BC%8Dquirksome-squares/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    int dp[4][50], size[4]={0}; // 4 種 digits (2, 4, 6, 8)
    int n;

    // 所有可能都找出來
    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j < 10000; j++) {
            int length = 10;
            // 左半與右半最多 4 個 digits
            for(int k = 0; k < 4; k++, length *= 10) {
                if((i+j)*(i+j) == i * length + j &&
                    i / length == 0 && j / length == 0)
                    dp[k][size[k]++] = i * length + j;
            }
        }
    }
    
    while(scanf("%d", &n) != EOF) {
        int dp_inx = n / 2 - 1;
        for(int i = 0; i < size[dp_inx]; i++)
            printf("%0*d\n", n ,dp[dp_inx][i]); // printf 自動補 0 的方法
    }
    return 0;
}