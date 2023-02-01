/*
    Keyword: BFS
    source1(answer): https://github.com/OmarSRehan/Competitive-Programming-Solutions/blob/master/UVA%20%23928%20-%20Eternal%20Truths.cpp
*/
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>
#include<iostream>
using namespace std;

#define VALID(I,J,N,M) ((I) >= 0 && (J) >= 0 && (I) < (N) && (J) < (M))
#define INF 1<<29
using namespace std;

int main()
{
    vector<vector<int>>dirs = {{-1,0}, {0, -1}, {0, 1}, {1, 0}};
    int T;
    while(scanf("%d", &T) != EOF) {
        while(T--) {
            int N, M, sourceX, sourceY, endX, endY;
            int preMove = 0, curMove = 1, curX, curY, nextX, nextY;
            scanf("%d%d", &N, &M);
            char graph[N][M];
            int d[N][M][4];
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++) {
                    cin >> graph[i][j];
                    d[i][j][1] = d[i][j][2] = d[i][j][3] = INF;
                    if(graph[i][j] == 'S'){sourceY = i, sourceX = j;};
                    if(graph[i][j] == 'E'){endY = i, endX = j;};
                }
            }

            queue<pair<pair<int,int>, int>>q;
            d[sourceY][sourceX][0] = 0;
            q.push(pair<pair<int,int>, int>(pair<int,int>(sourceY, sourceX), 0));
            bool found = false;
            while(!q.empty() && !found) {
                curY = q.front().first.first, curX = q.front().first.second;
                preMove = q.front().second, curMove = preMove%3+1;
                q.pop();
                for(int i = 0; i < 4; i++) {
                    nextY = curY + dirs[i][1]*curMove;
                    nextX = curX + dirs[i][0]*curMove;
                    if(VALID(nextY, nextX, N, M) && graph[nextY][nextX] != '#' && d[nextY][nextX][curMove] == INF) {
                        int bad = false;
                        for(int j = 1; j <= curMove; j++)
                            bad = bad || graph[curY + dirs[i][1]*j][curX + dirs[i][0]*j] == '#';
                        if(bad)continue;

                        d[nextY][nextX][curMove] =  d[curY][curX][preMove] + 1;
                        if(nextY == endY && nextX == endX)found = true;
                        q.push(pair<pair<int,int>,int>(pair<int,int>(nextY, nextX), curMove));
                    }
                }
            }

            if(!found)
                printf("NO\n");
            else
                printf("%d\n", d[endY][endX][curMove]);
        }
    }
    return 0; 
}


