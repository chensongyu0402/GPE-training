/*
    Keyword: MOD
    source1(answer): https://knightzone.studio/2012/01/19/1375/uva%EF%BC%9A374%EF%BC%8Dbig-mod/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

long long bigMod(long long B, long long P, long long M)
{
    if(P == 0)
        return 1;
    else if(P == 1)
        return B%M;
    else {
        long long result = bigMod(B, P/2, M);
        if(P%2 == 1)
            return result*result*B % M;
        else
            return result*result % M;
    }
}

int main()
{
    long long B, P, M;
    while(scanf("%lld%lld%lld", &B, &P, &M) != EOF) {
        printf("%lld\n", bigMod(B,P,M));
    }
    return 0;
}