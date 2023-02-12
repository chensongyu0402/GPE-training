/*
    Keyword: DP
    source1(answer): https://blog.csdn.net/mobius_strip/article/details/25924487
*/
#include<stdlib.h>
#include<memory.h>
#include<math.h>
#include<iostream>
using namespace std;

int a[10004];
int f[10004][104]; // f(i,j)為前 i 個數字組成的結果餘數可以為 j, 若為真就是 1

int main()
{
    int t, n, k;
    while(scanf("%d", &t) != EOF) {
        while(t--) {
            scanf("%d%d", &n, &k);
            for(int i = 0; i < n; i++)
                scanf("%d", &a[i]);
            for(int i = 0; i < n; i++)
                a[i] = abs(a[i])%k;
            
            memset(f, 0, sizeof(f));
            f[0][0] = 1;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < k; j++) {
                    if(f[i][j]) {
                        f[i+1][(j+k+a[i])%k] = 1;
                        f[i+1][(j+k-a[i])%k] = 1;
                    }
                }
            }
            if(f[n][0])
                printf("Divisible\n");
            else
                printf("Not divisible\n");
        }
    }
    return 0;
}