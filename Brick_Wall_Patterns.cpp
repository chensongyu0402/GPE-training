/*
    Keyword: 費氏數列
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int dp[55] = {0, 1, 2};

int main()
{
    for(int i = 3; i <= 50; i++)
        dp[i] = dp[i-1] + dp[i-2];
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        printf("%d\n", dp[n]);
    }
    return 0;
}