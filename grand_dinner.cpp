/*
    Keyword: greedy
    source1(answer): https://knightzone.studio/2016/04/24/3102/uva%EF%BC%9A10104%EF%BC%8Deuclid-problem/
*/
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct table
{
    int *t;    // 數量
    int index; // 桌數
} tb[51];

bool cmp(table a, table b)
{
    return *(a.t) > *(b.t);
}

int main()
{
    int M, N;
    int m[71], n[51];
    while (scanf("%d%d", &M, &N) != EOF) {
        if (M == 0 && N == 0)
            break;
        int ans[71][100]; // 每隊伍的位子情況
        for (int i = 0; i < M; i++)
            scanf("%d", &m[i]);
        for (int i = 0; i < N; i++)
            scanf("%d", &n[i]);

        bool flg = true;
        for (int i = 0; i < M && flg; i++) {
            // 人數多於桌數
            if (m[i] > N) {
                flg = false;
                break;
            }

            // 排序桌子數量 (多的優先)
            for (int j = 0; j < N; j++) {
                tb[j].t = &n[j]; // 可以避免重複存取原值，可以被更新(該位址)
                tb[j].index = j;
            }
            sort(tb, tb + N, cmp);

            int n_ans = 0;
            for (int j = 0; j < m[i]; j++) {
                if (*(tb[j].t) <= 0) {
                    flg = false;
                    break;
                }else {
                    (*(tb[j].t))--;
                    ans[i][n_ans++] = tb[j].index;
                }
            }
            sort(ans[i], ans[i] + n_ans);
        }
        if (flg)
        {
            printf("1\n");
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < m[i] - 1; j++) {
                    printf("%d ", ans[i][j] + 1);
                }
                printf("%d\n", ans[i][m[i] - 1] + 1);
            }
        }
        else
            printf("0\n");
    }
}