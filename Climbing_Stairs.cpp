
#include<stdlib.h>
#include<iostream>
using namespace std;
//const int MAXL(1e6);
const int MAX(1e8);
long long ans[101][50];

int main()
{
    ans[1][0] = 1, ans[2][0] = 2;
    int len = 0;
    for(int i = 3; i <= 100; i++) {
        long long carry = 0;
        for(int j = 0; j <= len; j++) {
            ans[i][j] = ans[i -1][j] + ans[i - 2][j] + carry;
            carry = ans[i][j] / MAX;
            ans[i][j] %= MAX;
        }
        if(carry > 0)
           ans[i][++len] = carry;
    }
    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i = len; i >= 0; i--) {
            if(ans[n][i] > 0) {
                printf("%lld",ans[n][i]);
            }
        }
        printf("\n");
    }
}
