/*
    Keyword: DFS
    source1(answer): https://theriseofdavid.github.io/2021/05/08/UVa/UVa10908/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;
const int maxINT = 120;
int t, q, m, n;
int direct[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; // 一定要有順序性，才能繞一圈
string map[maxINT];

bool isvalid(int x, int y)
{
    if(x >= m || y >= n || x < 0 || y < 0)
        return false;
    return true;
}

// DFS
int find_square(int x, int y)
{
    int d = 1; //正方形邊長
    char rc = map[x][y]; //root char
    int flag = 1; // is square

    while(flag) {
        d += 2;
        // 左上角
        int current_x = x - (d/2), current_y = y - (d/2);
        // if(isvalid(current_x, current_y) || map[current_x][current_y] != rc)break; 因為最後會確認一次
        // 往四個方向找 (繞一圈)
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < d - 1; j ++) {
                current_x += direct[i][0];
                current_y += direct[i][1];
                if(!isvalid(current_x, current_y) || map[current_x][current_y] != rc) {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0)
                break;
        }
    }
    return d - 2; // 最後一次是失敗的
}

int main()
{
    while(scanf("%d", &t) != EOF) {
        for(int caseIndex = 1; caseIndex <= t; caseIndex++) {
            cin >> m >> n >> q;
            for(int i = 0; i < m; i++)
               cin >> map[i];
            printf("%d %d %d\n", m, n, q);
            int x,y;
            for(int i = 0; i < q; i++) {
                cin >> x >> y;
                cout << find_square(x,y) << endl;
            }
        }
    }
    return 0;
}