/*
    Keyword: None
    source1(answer): https://hydingsy.github.io/articles/problem-UVa-10140-Prime-Distance/
*/
#include<stdlib.h>
#include<iostream>
#include<cstring>
using namespace std;

/*
    p 儲存 prime, tol 為他的 index
    flag 來判斷是不是 prime (0 is prime, 1 is not), vis 為 L 到 R 內是否為 prime (0 is not, 1 is prime)
*/
const int N = 1e6+5;
int total,p[N];
bool flg[N], vis[N];

// create prime table and flag table
void create() {
    for(int i = 2; i < N; i++) {
        if(!flg[i])p[++total] = i;
        for(int j = 1; j <= total && i*p[j] < N; j++) { // i*p[j] < N 因為最多到 sqrt(N)
            flg[i *p[j]] = 1;
            if(i%p[j] == 0)break; // 不是互質
        }
    }
}

void findmin (long long &x, long long a, long long b, long long &p1, long long &p2)
{
    if(x > b - a) x = b-a, p1 = a, p2 = b; // b -a 計算 prime distance
}

void findmax(long long &x, long long a, long long b, long long &p1, long long &p2)
{
    if(x < b - a) x = b-a, p1 = a, p2 = b;
}

int main()
{
    create();
    long long l, r;
    while(scanf("%lld %lld", &l, &r)!=EOF) {
        memset(vis, 1, sizeof(vis));
        if(l == 1)vis[0] = 0;
        for(int i = 1; i <= total; i++) {
            // 標記 L to R 間的 prime
            for(int j = l/p[i]; j * p[i] <= r; j++) {
                long long x = p[i] * j;
                if(j > 1 && x >= 1)vis[x-l] = 0;
            }
        }
        // 在 L to R 間開始計算 prime distance
        long long p = 0, p1, p2, p3, p4, mn = 1LL<<60, mx = 0;
        for(long long i = l; i <= r; i++) {
            if(!vis[i - l])continue;
            if(p) findmin(mn, p, i, p1, p2), findmax(mx, p, i, p3, p4);
            p = i;
        }
        if(!mx)
            printf("There are no adjacent primes.\n");
        else
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n", p1, p2, p3, p4);
    }
    return 0;
}