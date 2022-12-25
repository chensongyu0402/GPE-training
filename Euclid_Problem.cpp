/*
    Keyword: gcd
    source1(answer): https://knightzone.studio/2016/04/24/3102/uva%EF%BC%9A10104%EF%BC%8Deuclid-problem/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int gcd(int A, int B, int &X, int &Y)
{
    if(A % B == 0) {
        X = 0;
        Y = 1;
        return B;
    }
    if(B % A == 0) {
        X = 1;
        Y = 0;
        return A;
    }
    if(A >= B) {
        int x, y;
        int value = gcd(A+B*(-A/B), B, x, y);
        X = x;
        Y = y + x * (-A/B);
        return value;
    }else {
        int x, y;
        int value = gcd(A, B + A*(-B/A), x, y);
        X = x + y * (-B/A);
        Y = y;
        return value;
    }
}

int main()
{
    int A, B;
    while(scanf("%d%d", &A, &B)!=EOF) {
        int X, Y;
        int value = gcd(A, B, X, Y);
        printf("%d %d %d\n", X, Y, value);
    }
    return 0;
}
