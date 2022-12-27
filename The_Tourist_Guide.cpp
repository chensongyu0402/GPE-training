/*
    Keyword: Floyd-Warshall, shortest path
    source1(answer): https://knightzone.studio/2016/03/17/3032/uva%EF%BC%9A10099%EF%BC%8Dthe-tourist-guide/
*/
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int scenario = 0;
    int N, R;
    int capacity[105][105] = {0};
    while(scanf("%d%d", &N, &R) != EOF) {
        if(N == 0 && R == 0)break;
        for(int i = 0; i < R; i++) {
            int c1, c2, p;
            scanf("%d%d%d", &c1, &c2, &p);
            capacity[c1][c2] = capacity[c2][c1] = p; //two-way roads
        }

        // Floyd-Warshall, 最多(max)可載客數, min 是因為有限制載客數
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++)
                for(int k = 1; k <= N; k++)
                    capacity[i][j] = max(capacity[i][j], min(capacity[i][k], capacity[k][j]));
        
        int S, D, T;
        scanf("%d%d%d", &S, &D, &T);
        int trip = T / (capacity[S][D] - 1); // - 1 ==> 因為有導遊
        if(T%(capacity[S][D] - 1) > 0)
            trip += 1;
        printf("Scenario #%d\n", ++scenario);
        printf("Minimum Number of Trips = %d\n", trip);
    }
    return 0;
}
