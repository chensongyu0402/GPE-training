/*
    Keyword: BFS, DFS
    source1(answer): https://knightzone.studio/2012/01/18/1346/uva%EF%BC%9A10336%EF%BC%8Drank-the-languages/
*/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

char map[1000][1000]={0};
bool visited[1000][1000]={0};
int direct[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int N, H, W;

void DFS(int x, int y)
{
    visited[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nextx = x + direct[i][0];
        int nexty = y + direct[i][1];
        if(nextx < 0 || nexty < 0 || nextx >= H || nexty >= W
           || map[x][y] != map[nextx][nexty] || visited[nextx][nexty])
           continue;
        DFS(nextx, nexty);
    }
}

int main()
{
    while(scanf("%d", &N) != EOF) {
        for(int caseIndex = 1; caseIndex <= N; caseIndex++) {
            // initial
            memset(visited,0,sizeof(visited)); //from string.h
            int area[30] = {0};
            int maxarea = 0;
            scanf("%d %d", &H, &W);
            getchar(); //避免 enter
            for(int i = 0; i < H; i++) {
                for(int j = 0; j < W; j++) {
                    scanf("%c",&map[i][j]);
                }
                getchar(); //避免 enter
            }
            for(int i = 0; i < H; i++) {
                for(int j = 0; j < W; j++) {
                    if(!visited[i][j]) {
                        area[map[i][j] - 'a'] ++;
                        maxarea = max(area[map[i][j] - 'a'], maxarea);
                        DFS(i,j);
                    }
                }
            }
            printf("World #%d\n",caseIndex);
            for(int i = maxarea; i > 0; i--) {
                for(int j = 0; j < 26; j++) {
                    if(area[j] == i)
                        printf("%c: %d\n", 'a'+j, i);
                }
            }
        }
    }
    system("pause");
    return 0;
}