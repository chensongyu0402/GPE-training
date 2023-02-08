/*
    Keyword: dp
    source1(answer): https://github.com/morris821028/UVa/blob/master/OnlineJudge/LeetCodeOJ/64%20-%20Minimum%20Path%20Sum.cpp
*/
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int t;
    while(scanf("%d", &t) != EOF) {
        while(t--) {
            int r, c;
            scanf("%d%d", &r, &c);
            vector<vector<int>>map(r, vector<int>(c, 0));
            for(int i = 0; i < r; i++)
                for(int j = 0; j < c; j++)
                    cin >> map[i][j];

            for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                    if(i > 0 && j > 0)map[i][j] += min(map[i-1][j], map[i][j-1]);
                    else if(i == 0 && j > 0)map[i][j] += map[i][j-1];
                    else if(i > 0 && j == 0)map[i][j] += map[i-1][j];
                }
            }
            printf("%d\n", map[r-1][c-1]);
        }
    }
    return 0;
}