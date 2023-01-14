/*
    Keyword: None
    source1(answer): https://blog.csdn.net/mobius_strip/article/details/79696605
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int visit[35000] = {0};
int prime[4000];

int main()
{
    int prime_size = 0;
    for(int i = 2; i < 35000; i++) {
        if(!visit[i]) {
            prime[prime_size++] = i;
            for(int j = i + i; j < 35000; j += i)
                visit[j] = 1;
        }
    }

    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        int ans = 0;
        for(int i = 2; i <= n; i++)
            ans = (ans + prime[n-i])%i;
        printf("%d\n",ans + 1);
    }
    return 0;
}