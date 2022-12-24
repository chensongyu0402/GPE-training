/*
    Keyword: DP
    source1(answer): https://blog.csdn.net/mobius_strip/article/details/41841777
*/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
/**/
long long f[23001]; //DP table (450*100/2 --> 23001)
int h[101]; // 重量

int gcd(int a, int b)
{
    if(b == 0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int t, n, sum, r;
    while(scanf("%d", &t) != EOF) {
        while(t--) {
            scanf("%d", &n);
            sum = 0;
            for(int i = 1; i <= n; i++) {
                scanf("%d", &h[i]);
                sum += h[i];
            }
            // 優化，為了讓計算量減少，所以讓所有值去除以大家的最大公因數
            r = 1;
            if(n > 0) {
                r = h[1];
                for(int i = 2; i <= n; i++)
                    r = gcd(r, h[i]);
                sum /= r;
                for(int i = 1; i <= n; i++)
                    h[i] /= r;
            }
            /*
                //f（i）表示總重為i時的所有可能的人數，f（i）的值，的第k位上的數是 1，則代表有k人的组合方式
                //f（i）= f（i）| （f（i-w[j]）<< 1） ==> 可以更新到本狀態的狀態人數集合各加1(因為有新的人加入)與原来集合的合
            */
            for(int i = 0; i <= sum/2; i++)
                f[i] = 0LL;
            f[0] = 1LL;
            for(int i = 1; i <= n; i++)
                for(int j = sum/2; j >= h[i]; j--)
                    f[j] |= f[j-h[i]]<<1;
        
            int move = sum/2 + 1; // 因為盡量要一半一半
            while(move --) {
                if(n%2 == 0 && f[move]&(1LL<<((n+1)/2)))break;
                if(n%2 == 1 && f[move]&(1LL<<((n+0)/2)))break;
                if(n%2 == 1 && f[move]&(1LL<<((n+1)/2)))break; // 因為人數不差一
            }
            printf("%d %d\n", move*r, (sum - move)*r);
            if(t)printf("\n");
        }    
    }
    return 0;
}