/*
    Keyword: extend gcd
    source1(answer): https://blog.csdn.net/mobius_strip/article/details/78189231
*/
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

void exgcd(long long a, long long b, long long &r, long long &x, long long &y)
{
    if(!b) {
        r = a; // r = gcd(a,b)
        x = 1;
        y = 0;
    }else {
        exgcd(b, a%b, r, y, x);
        y -= (a/b)* x;
    }
}

int main()
{
    long long n, c1, n1, c2, n2, r, x, y;
    while(scanf("%lld", &n) && n) {
        scanf("%lld%lld%lld%lld", &c1, &n1, &c2, &n2);

        exgcd(n1, n2, r, x, y);
        long long lower = ceil(-1.0*n*x/n2);
        long long upper = floor(1.0*n*y/n1);

        if(n%r || lower > upper) {
            printf("failed\n");
        } else if (c1 * n2 >= c2 * n1) {
            x = x * n / r + n2 / r * lower;
            y = y * n / r - n1 / r * lower;
            printf("%lld %lld\n", x, y);
        }else {
            x = x * n / r + n2 / r * upper;
            y = y * n / r - n1 / r * upper;
            printf("%lld %lld\n", x, y);
        }
    }
    return 0;
}