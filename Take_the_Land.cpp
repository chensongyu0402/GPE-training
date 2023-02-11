/*
    Keyword: DP
    source1(answer): https://knightzone.studio/2020/05/09/4942/uva%EF%BC%9A10074%EF%BC%8Dtake-the-land/
*/
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int m, n;
    while(scanf("%d%d", &m, &n) != EOF) {
        if(m == 0 && n == 0)break;
        vector<vector<int>>map(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &map[i][j]);
        
        int maxAllZeroArea = 0; //ans
        for(int startRow = 0; startRow < m; startRow++) {
            vector<bool>sameColumnInAllZeroDP(n, true); //到該列的那一行是否都是 0
            for(int endRow = startRow; endRow < m; endRow++) { //每種都考慮進去
                for(int column = 0; column < n; column++)
                    sameColumnInAllZeroDP[column] = 
                    (sameColumnInAllZeroDP[column] && (map[endRow][column] == 0));
                // 可以想像成計算矩形的初始設定
                bool isAllZeroResult = sameColumnInAllZeroDP[0];
                int startColumn = 0;
                int endColumn = 0;
                if(isAllZeroResult)
                    maxAllZeroArea = max(maxAllZeroArea, (endRow - startRow + 1)); //與直的一條比
                
                for(int column = 1; column < n; column++) {
                    if(!isAllZeroResult) {
                        isAllZeroResult = sameColumnInAllZeroDP[column];
                        startColumn = column;
                        endColumn = column;
                    }else {
                        isAllZeroResult = isAllZeroResult && sameColumnInAllZeroDP[column];
                        endColumn = column;
                    }

                    if(isAllZeroResult) {
                        maxAllZeroArea = max(maxAllZeroArea, 
                                         (endRow - startRow + 1)*(endColumn - startColumn + 1));
                    }
                }
            }
        }
        printf("%d\n", maxAllZeroArea);
    }
    return 0;
}