/*
    Keyword: DP
    source1(answer): https://www.pinghenotes.com/UVa-10912-Simple-Minded-Hashing/
*/
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
/*
    dp[i][j][k] --> i 為 字母要選或是不選, j 為長度, k 為值
    長度為 26 是因為 strictly ascending order, 所以最多 26
    值為 352 是因為 1 + 2 + ... + 26 = 351
*/
int dp[27][27][352]; 
int main()
{
    int L, S, Ncase = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0]= 1;
    for(int i = 1; i <= 26; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k <= 351; k++) {
                dp[i][j][k] = dp[i-1][j][k];
                if(j && k >= i) // 避免 k - i < 0
                    dp[i][j][k] += dp[i-1][j-1][k-i];
            }
        }
    }
    while(scanf("%d%d", &L, &S) != EOF) {
        if(L == 0 && S == 0)
            break;
        if(L <= 26 && S <= 351)
            printf("Case %d: %d\n", ++Ncase, dp[26][L][S]);
        else
            printf("Case %d: 0\n", ++Ncase);
    }

}