/*
    Keyword: None
    source1(answer): https://a7069810.pixnet.net/blog/post/395133313-%5Buva10209%5D-is-this-integration%3F
    source2(output): https://knightzone.studio/2011/12/01/1251/uva%EF%BC%9A10209%EF%BC%8Dis-this-integration/
*/
#include<stdlib.h>
#include<iostream>
#include<math.h>
#define PI (2 * acos(0.0))
using namespace std;

int main()
{
    double a;
    while(scanf("%lf", &a) != EOF) {
        double x, y, z; // stripe, dot, rest
        z = a*a - (a*a*PI)/6.0 - (a*a*sqrt(3.0))/4.0; //每個
        y = a*a - (a*a*PI)/4.0 - (2.0*z);//每個
        x = a*a - 4.0*z - 4.0*y;//每個
        printf("%.3lf %.3lf %.3lf\n", x, 4*y, 4*z);
    }
    return 0;
}