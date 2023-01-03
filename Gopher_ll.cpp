/*
    Keyword: DFS
    source1(answer): http://programming-study-notes.blogspot.com/2014/05/uva-10080-gopher-ii.html
    source2(chinese): http://web.kshs.kh.edu.tw/academy/luckycat/homework/q10080.htm
*/
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<memory.h>
using namespace std;

struct Point{
    double x;
    double y;
};

bool edge[105][105];
bool visited[105];
int llink[105];
int rlink[105];

bool DFS(int now, const int &m)
{
    for(int nxt = 0; nxt < m; nxt++) {
        if(edge[now][nxt] == false || visited[nxt])continue;

        visited[nxt] = true;
        // 若洞裡沒有人或是(如果有人，就幫他重新排一個洞看看)
        if(rlink[nxt] == -1 || DFS(rlink[nxt], m)) {
            llink[now] = nxt;
            rlink[nxt] = now;
            return true;
        }
    }
    return false;
}

int main()
{
    int n,m,s,v;
    Point gopher[105], hole[105];
    while(scanf("%d%d%d%d", &n, &m, &s, &v) != EOF) {
        // input
        for(int i = 0; i < n; i++)scanf("%lf%lf", &gopher[i].x, &gopher[i].y);
        for(int i = 0; i < m; i++)scanf("%lf%lf", &hole[i].x, &hole[i].y);
        // distance
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                double dis = sqrt(pow(gopher[i].x - hole[j].x, 2) + pow(gopher[i].y - hole[j].y, 2));
                if(dis / v <= s)
                    edge[i][j] = true;
                else
                    edge[i][j] = false;
            }
        }
        //Bipartite
        int ans = 0;
        memset(llink, -1, sizeof(llink));
        memset(rlink, -1, sizeof(rlink));
        for(int i = 0; i < n; i++) {
            memset(visited, false, sizeof(visited));
            if(DFS(i, m))
                ++ans;
        }
        printf("%d\n", n - ans);
    }
    return 0;
}