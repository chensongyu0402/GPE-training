/*
    Keyword: DP
    source1(answer): https://blog.csdn.net/keshuai19940722/article/details/11544919
*/
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
const int N = 1000005;
int n, m, dp[N], val[20];
int main()
{
    while(1) {
        int n,m;
        scanf("%d%d", &n, &m);
        memset(dp, 0, sizeof(dp));
        memset(val, 0, sizeof(val));
        for(int j = 0; j < m; j++)
            scanf("%d", &val[j]);
        
        // 0 : 輸, 1 : 贏
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < m; j++) {
                if(i - val[j] >= 0 && !dp[i - val[j]]) { //還有剩下 且 對方輸了
                    dp[i] = 1;
                    break; // 有勝出就不用比下去了
                }
            }
        }
        if(dp[n])
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
