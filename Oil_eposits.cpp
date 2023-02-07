/*
    Keyword: BFS
    source1(answer): https://knightzone.studio/2014/12/29/2471/uva%EF%BC%9A572%EF%BC%8Doil-deposits/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

const int maxL = 100;

void visit(bool isVisited[][maxL+5], 
           char map[][maxL+5],
           int i, int j)
{
    if(map[i][j] == '@' && !isVisited[i][j]) {
        isVisited[i][j] = true;
        visit(isVisited, map, i-1, j);
        visit(isVisited, map, i+1, j);
        visit(isVisited, map, i, j-1);
        visit(isVisited, map, i, j+1);
        visit(isVisited, map, i-1, j+1);
        visit(isVisited, map, i-1, j-1);
        visit(isVisited, map, i+1, j-1);
        visit(isVisited, map, i+1, j+1);
    }
}

int main()
{
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        if(m == 0)break;
        char map[maxL+5][maxL+5] = {0};
        for(int i = 1; i <= m; i++)
            cin >> map[i];
        
        bool isVisited[maxL+5][maxL+5] = {false};
        int Oil = 0;
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(map[i][j] == '@' && !isVisited[i][j]) {
                    Oil ++;
                    visit(isVisited, map, i, j);
                }
            }
        }
        printf("%d\n", Oil);
    }
    return 0;
}