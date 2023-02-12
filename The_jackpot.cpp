/*
    Keyword: DP
    source1(answer): https://knightzone.studio/2014/12/23/2433/uva%EF%BC%9A10684%EF%BC%8Dthe-jackpot/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        int sequences[10005] = {0};
        for(int i = 1; i <= n; i++)
            scanf("%d", &sequences[i]);
        int dp[10005] = {0};
        int win = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = max(sequences[i], sequences[i] + dp[i-1]);
            win = max(win, dp[i]);
        }
        if(win > 0)
            printf("The maximum winning streak is %d.\n", win);
        else
            printf("Losing streak.\n");
    }
    return 0;
}