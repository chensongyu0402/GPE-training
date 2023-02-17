/*
    Keyword: math
    source1(chinese): https://blog.csdn.net/mobius_strip/article/details/76595464
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    double vt, v0;
    while(scanf("%lf%lf",&vt, &v0) != EOF) {
        if(vt == 0 && v0 == 0)break;
        if(vt <= v0) {
            printf("0\n");
        }else if(vt <= 2*v0) {
            printf("1\n");
        }else {
            if(0.5*vt/v0 - int(0.5*vt/v0) == 0.5) {
                printf("0\n");
            }else if(0.5*vt/v0 - int(0.5*vt/v0) < 0.5) {
                printf("%d\n", int(0.5*vt/v0));
            }else {
                printf("%d\n", int(0.5*vt/v0) + 1);
            }
        }
    }
    return 0;
}
