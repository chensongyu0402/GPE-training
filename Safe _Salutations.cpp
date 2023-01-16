/*
    Keyword: Catalan number
    source1(answer): https://yuihuang.com/uva-991/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;
const int maxn = 25;
int C[maxn][maxn];

int main()
{
    for(int i = 0; i < maxn; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
    }

    for(int i = 1; i < maxn; i++)
        for(int j = 1; j < i; j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
    
    int n;
    bool first = true;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        if(first)
            first = false;
        else
            printf("\n");
        printf("%d\n", C[2*n][n]/(n+1));
    }
    return 0;
}