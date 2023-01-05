/*
    Keyword: None
    source1(answer): https://blog.csdn.net/tengfei461807914/article/details/53143336
*/
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<memory.h>
#include<cmath>
using namespace std;

double circle[10], X[10];
double ans;
const double inf = 99999999;
int n;

double db_abs(double x)
{
    if(x < 0)
        return -x;
    else
        return x;
}

double dis_cc(int c1, int c2)
{
    double a = circle[c1] + circle[c2];
    double b = db_abs(circle[c1] - circle[c2]);
    return sqrt(a*a-b*b);
}

void solve ()
{
    do
    {
        memset(X, -1, sizeof(X));
        X[1] = circle[1];
        double tmp = -1;
        for(int i = 2; i <= n; i++) {
            double x_tmp = circle[i];
            for(int j = 1; j<i; j++) {
                x_tmp = max(x_tmp, X[j] + dis_cc(i,j));
            }
            X[i] = x_tmp;
        }

        for(int i = 1; i <= n; i++)
            tmp = max(tmp, X[i] + circle[i]);
        ans = min(ans, tmp);
    }while(next_permutation(circle + 1, circle + 1 + n)); // https://blog.csdn.net/HowardEmily/article/details/68064377
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            cin >> circle[i];
        sort(circle + 1, circle + 1 + n);
        ans = inf;
        solve();
        printf("%.3f\n", ans);
    }
    return 0;
}