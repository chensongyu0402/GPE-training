/*
    Keyword: Catalan number, big number
    source1(answer): https://www.codeleading.com/article/74213429968/
*/
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
const int MAXL(1e6);
const int MAX(1e8);
// ans = (n+2) * (n+3) * ….* ( 2*n ) 
long long ans[MAXL + 50];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF && n) {
        ans[0] = 1;
        int len = 0;
        for(int i = n+2; i <= 2*n; i++) {
            int carry = 0;
            for(int j = 0; j <= len; j++) {
                ans[j] = ans[j]*i + carry;
                carry = ans[j] / MAX;
                ans[j] %= MAX;
            }
            if(carry > 0)
                ans[++len] = carry;
        }
        printf("%lld", ans[len]);
        for(int i = len-1; i >= 0; i--)
            printf("%08lld",ans[i]);
        printf("\n");
    }
    return 0;
}