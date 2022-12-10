/*
    Keyword: DP, coin change
    source1(answer): https://knightzone.studio/2012/03/28/1548/uva%EF%BC%9A147%EF%BC%8Ddollars/
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    long long dp[30005];
    dp[0] = 1;
    int n1, n2;
    int dollars[] = {10000, 5000, 2000, 1000, 500,
                     200, 100, 50, 20, 10, 5};
    
    for(int i = 10; i >=0; i--)
        for(int j = dollars[i]; j <= 30000; j++)
            dp[j] += dp[j - dollars[i]];
    
    while(scanf("%d.%d",&n1,&n2) != EOF && !(n1 == 0 && n2 == 0)) {
        printf("%3d.%02d%17lld\n", n1, n2, dp[n1*100+n2]);
    }
    return 0;
}

