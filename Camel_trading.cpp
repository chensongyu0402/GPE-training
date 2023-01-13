/*
    Keyword: DP
    source1(answer): https://blog.csdn.net/mobius_strip/article/details/41281305
*/
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

char buf[101];
char oper[15];
int data[15];
long long f[15][15], t[15][15];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        while(n--) {
            scanf("%s", buf);
            int count = 1;
            data[count] = 0;
            // create operator and data array
            for(int i = 0; buf[i]; i++) {
                if(buf[i] == '*' || buf[i] == '+') {
                    oper[count] = buf[i];
                    data[++count] = 0;
                } else {
                    data[count] *= 10;
                    data[count] += buf[i] - '0';
                }
            }

            // initial DP
            for(int i = 1; i <= count; i++)
                f[i][i] = t[i][i] = data[i];
            // DP
            for(int l = 2; l <= count; l++) {
                for(int s = 1; s+l-1 <= count; s++) {
                    f[s][s+l-1] = 0LL, t[s][s+l-1] = 5000000000000000LL;
                    for(int k = s; k < s+l-1; k++) {
                        // find max
                        if(oper[k] == '+' && f[s][s+l-1] < f[s][k] + f[k+1][s+l-1])
                            f[s][s+l-1] = f[s][k] + f[k+1][s+l-1];
                        if(oper[k] == '*' && f[s][s+l-1] < f[s][k] * f[k+1][s+l-1])
                            f[s][s+l-1] = f[s][k] * f[k+1][s+l-1];
                        // find min
                        if(oper[k] == '+' && t[s][s+l-1] > t[s][k] + t[k+1][s+l-1])
                            t[s][s+l-1] = t[s][k] + t[k+1][s+l-1];
                        if(oper[k] == '*' && t[s][s+l-1] > t[s][k] * t[k+1][s+l-1])
                            t[s][s+l-1] = t[s][k] * t[k+1][s+l-1];
                    }
                }
            }
            printf("The maximum and minimum are %lld and %lld.\n", f[1][count], t[1][count]);
        }
    }
}