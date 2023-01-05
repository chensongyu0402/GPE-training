/*
    Keyword: None
    source1(answer): https://blog.csdn.net/mobius_strip/article/details/44867303
*/
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

typedef struct pnode
{
    double x, y, r;
    pnode(){};
    pnode(double X, double Y, double R){x = X, y = Y, r = R;};
    pnode(pnode a, pnode b) {
        x = (a.x + b.x) / 2;
        y = (a.y + b.y) / 2;
        r = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y))/2;
    }
}point;

point P[105];

double dist_p(point a, point b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

// 外心
point circle(point a, point b, point p)
{
    double A1 = a.x-b.x, B1 = a.y-b.y, C1 = (a.x*a.x-b.x*b.x+a.y*a.y-b.y*b.y)/2;
    double A2 = p.x-b.x, B2 = p.y-b.y, C2 = (p.x*p.x-b.x*b.x+p.y*p.y-b.y*b.y)/2;
    point c;
    c.x = (C1*B2 - C2*B1)/(A1*B2-A2*B1);
    c.y = (A1*C2-A2*C1)/(A1*B2-A2*B1);
    c.r = dist_p(c, a);
    return c;
}

point smallest_enclosing_circle(point P[], int n)
{
    random_shuffle(P, P+n);
    point c = point(P[0], P[1]);
    for(int i = 2; i < n; i++) {
        if(dist_p(c, P[i]) > c.r+1e-6) { // 超出半徑外
            c = point(P[0], P[i]);
            for(int j = 1; j < i; j++) {
                if(dist_p(P[j], c) > c.r+1e-6) {
                   c = point(P[i], P[j]);
                    for(int k = 0; k < j; k++) {
                        if(dist_p(P[k], c) > c.r+1e-6) {
                            c = circle(P[i], P[j], P[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}

int main()
{
    int n;
    double r;
    while(scanf("%d", &n) != EOF) {
        if(n==0)break;
        for(int i = 0; i < n; i++)
            scanf("%lf%lf", &P[i].x, &P[i].y);
        scanf("%lf", &r);
        point c = smallest_enclosing_circle(P, n);
        if(c.r < r+1e-6)
            printf("The polygon can be packed in the circle.\n");
        else
            printf("There is no way of packing that polygon.\n");
    }
    return 0;
}