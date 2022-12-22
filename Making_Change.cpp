/*
    Keyword: DP
    source1(answer1 --> 有點問題): http://naivered.github.io/2018/03/24/Problem_Solving/UVa/UVa-166-Making-Change/
    source2(answer2 --> 正確的): https://blog.csdn.net/tengfei461807914/article/details/52235050
*/

#include<stdlib.h>
#include<iostream>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define N 601 // 因為最多可以有 3 個 200
using namespace std;
int main()
{
    const int coin[6] = {5, 10, 20, 50, 100, 200};
    int have[6];
    int dp[N] = {}; // the number of coins
    int change[N] = {}; // 如果 201 會有問題 (p - price > 201)
    // 可以換到的最少零錢數目
    for(int i = 1; i < N; i++) {
        int temp = i;
        for(int k = 5; k >= 0 && temp; k--) {
            change[i] += temp / coin[k];
            temp %= coin[k];
        }
    }

    while(scanf("%d%d%d%d%d%d", &have[0], &have[1], &have[2], &have[3], &have[4], &have[5])) {
        // sum
        int sum = 0;
        for(int i = 0; i <= 5; i++)
            sum += coin[i] * have[i];
        if(sum == 0)
            break;
        // price
        int a, b;
        scanf("%d.%d", &a, &b);
        int price = 0;
        price = a * 100 + b;
        // dp
        for(int i = 0; i < N; i++)
            dp[i] = 1e9;
        dp[0] = 0;
        for(int i = 0; i < 6; i++)
            for(int j = 1; j <= have[i]; j++)
                for(int k = MIN(600, sum); k >= coin[i] * j; k--)
                    dp[k] = MIN(dp[k], dp[k - coin[i] * j] + j);
        // get ans 付出的零錢 + 大於價錢時的找零，最小的即為答案
        int min = 1e9;
        for(int k = MIN(600, sum); k >= price; k--) {
            if(dp[k] < 1e9) {
                if(k > price)
                    dp[k] += change[k - price];
                if(dp[k] < min)
                    min = dp[k];
            }
        }
        printf("%3d\n", min);
    }
    return 0;
}