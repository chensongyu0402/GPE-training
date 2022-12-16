/*
    Keyword: big number
    source1(answer): https://github.com/morris821028/UVa/blob/master/volume102/10254%20-%20The%20Priest%20Mathematician.cpp
    source2(規律) : http://www.aspphp.online/bianchen/cyuyan/cjj/cjjrm/201701/219325.html
*/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;
int bin[150][100]={};
int ans[10001][100]={};

void build()
{
    int i, j, k, la = 0, idx = 2;
    ans[1][0] = 1;
    bin[0][0] = 1;

    for(i = 1; i < 150; i++) {
        // bin --> 2^n
        for(j = 0; j <= la; j++)
            bin[i][j] = bin[i - 1][j]*2;
        // bin to big number
        for(j = 0; j <= la; j++) {
            if(bin[i][j] >= 10) {
                bin[i][j + 1] +=  bin[i][j]/10;
                bin[i][j] = bin[i][j]%10;
            }
        }
        if(bin[i][la+1])la++;
        // ans[i] = ans[i -1] + 2^n
        k = i + 1;
        while(k && idx <= 10000) {
            for(j = 0; j < 99; j++)
                ans[idx][j] = ans[idx - 1][j] + bin[i][j];
            // ans to big number
            for(j = 0; j < 99; j++) {
                if(ans[idx][j] >= 10) {
                    ans[idx][j + 1] +=  ans[idx][j]/10;
                    ans[idx][j] = ans[idx][j]%10;
                }
            }
            idx ++;
            k --;
        }
    }
}

int main()
{
    build();
    int n, i;
    while(scanf("%d", &n) != EOF) {
        if(n == 0) {
            printf("0"); // putchar('0');
        }
        for(i = 99; i >= 0; i--)
            if(ans[n][i])
                break;
        while(i >= 0) {
            printf("%d",ans[n][i]);
            i --;
        }
            //putchar(ans[n][i] + '0');
        //puts("");
        printf("\n");
    }
    return 0;
}