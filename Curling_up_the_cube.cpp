/*
    Keyword: None
    source1(answer): https://blog.csdn.net/mobius_strip/article/details/50589901
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

// 列出所有可以組成正立方體的可能 (共 11 個)
int row[11] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2}; // 每個立方體的 row 數
int col[11] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5};// 每個立方體的 column 數
int blocks[11][3][5] = {
    1,0,0,0,0,  1,1,1,1,1,  1,0,0,0,0,
    1,0,0,0,0,  1,1,1,1,1,  0,1,0,0,0,
    1,0,0,0,0,  1,1,1,1,1,  0,0,1,0,0,
    1,0,0,0,0,  1,1,1,1,1,  0,0,0,1,0,
    0,1,0,0,0,  1,1,1,1,1,  0,1,0,0,0,
    0,1,0,0,0,  1,1,1,1,1,  0,0,1,0,0,
    1,0,0,0,0,  1,1,1,0,0,  0,0,1,1,0,
    0,1,0,0,0,  1,1,1,0,0,  0,0,1,1,0,
    0,0,1,0,0,  1,1,1,0,0,  0,0,1,1,0,
    1,1,0,0,0,  0,1,1,0,0,  0,0,1,1,0,
    1,1,1,0,0,  0,0,1,1,1,  0,0,0,0,0
};

// M 為被處理過後, S 正在被使用
int m[6][6], s[6][6];

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF) {
        while(n --) {
            for(int i = 0; i < 6; i++)
                for(int j = 0; j < 6; j++)
                    cin >> m[i][j];
            int find = 0;
            //總共會找 11 次 (1 次正常 + 3 次旋轉 90 度 + 1 次翻面 + 3 次旋轉 90 度) 
            for(int k = 0; k < 8; k++) {
                // store m to s
                for(int i = 0; i < 6; i++)
                    for(int j = 0; j < 6; j++)
                        s[i][j] = m[i][j];
                // 11 種可能都去找
                for(int t = 0; t < 11 && !find; t++) {
                    for(int x = 0; x <= 6 - row[t] && !find; x++) {
                        for(int y = 0; y <= 6 - col[t] && !find; y++) {
                            int sum = 0;
                            for(int p = 0; p < row[t]; p++) {
                                for(int q = 0; q < col[t]; q++) {
                                    if(s[x+p][y+q] && blocks[t][p][q])
                                        sum ++;
                                }
                            }
                            if(sum == 6) {
                                find = 1;
                                break;
                            }
                        }
                    }
                }
                if(find)break;
                // 旋轉與翻轉
                for(int i = 0; i < 6; i++) {
                    for(int j = 0; j < 6; j++)
                        m[i][j] = s[5 -j][i]; //翻轉
                }
                if(k == 3) {
                    for(int i = 0; i < 6; i++) {
                        for(int j = 0; j < i; j++) {
                            // 旋轉
                            m[i][j] ^= m[j][i];
                            m[j][i] ^= m[i][j];
                            m[i][j] ^= m[j][i]; 
                        }
                    }
                }
            }
            if(find)   
                puts("correct");
            else
                puts("incorrect");
            if (n) puts("");
        }
    }
    return 0;
}
