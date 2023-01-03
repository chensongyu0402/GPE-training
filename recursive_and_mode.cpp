/*
    Keyword: None
    source1(answer): https://slides.com/allenwhale/deck-3/fullscreen
*/
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

long long MOD = pow(10, 9) + 9;
long long fast_pow(long long a, long long n)
{
    if(n == 0)
        return 1;
    long long half = fast_pow(a, n / 2);
    if(n&1 == 1)
        return (((half * half)%MOD)*a)%MOD;
    else
        return (half * half)%MOD;
}

int main()
{
    long long n;
    while(scanf("%lld", &n) != EOF) {
        long long ans = (fast_pow(3, n) - 2)%MOD;
        printf("%lld\n",ans);
    }
    return 0;
}