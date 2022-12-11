/*
    Keyword: BFS
    source1(answer): https://knightzone.studio/2014/10/06/2248/uva%EF%BC%9A532%EF%BC%8Ddungeon-master/
*/
#include<stdlib.h>
#include<queue>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

struct Point{
    int l;
    int r;
    int c;
    int value; // step
    Point(int l, int r, int c, int value):
        l(l), r(r), c(c), value(value){};
};

int BFS(string map[][35],
        int L, int R, int C,
        int point_l, int point_r, int point_c)
{
    queue<Point>bfs;
    bfs.push(Point(point_l, point_r, point_c, 0));
    while(!bfs.empty()) {
        Point p = bfs.front();

        // 邊界
        if(p.l < 0 || p.r < 0 || p.c < 0 ||
           p.l >= L || p.r >= R || p.c >= C) {
            bfs.pop();
            continue;
        }
        // 成功
        if(map[p.l][p.r][p.c] == 'E')
            return p.value;
        // ##
        if(map[p.l][p.r][p.c] != '.') {
            bfs.pop();
            continue;
        }
        // ..
        map[p.l][p.r][p.c] = '#';
        // search
        bfs.push(Point(p.l + 1, p.r, p.c, p.value + 1));
        bfs.push(Point(p.l - 1, p.r, p.c, p.value + 1));
        bfs.push(Point(p.l, p.r + 1, p.c, p.value + 1));
        bfs.push(Point(p.l, p.r - 1, p.c, p.value + 1));
        bfs.push(Point(p.l, p.r, p.c + 1, p.value + 1));
        bfs.push(Point(p.l, p.r, p.c - 1, p.value + 1));

        bfs.pop();
    }
    return -1;
}

int main()
{
    int L, R, C;
    while(scanf("%d %d %d", &L, &R, &C)!=EOF &&
          L != 0 && R!= 0 && C!= 0) {
        string map[35][35];
        int start_l, start_r, start_c;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < R; j++) {
                cin >> map[i][j];
                for(int k = 0; k < C; k++) {
                    if(map[i][j][k] == 'S') {
                        start_l = i;
                        start_r = j;
                        start_c = k;
                        map[i][j][k] = '.';
                    }
                }
            }
        }

        int ans = BFS(map, L, R, C, start_l, start_r, start_c);
        if(ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}