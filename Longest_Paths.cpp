/*
    Keyword: SPFA, Bellman-Ford
    source1(answer): https://knightzone.studio/2016/04/28/3127/uva%EF%BC%9A10000%EF%BC%8Dlongest-paths/
*/
#include<stdlib.h>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;
// s -> source, n -> number of points
int longestPath(bool map[105][105], vector<int> &distancce, int s, int n)
{
    // initial
    distancce[s] = 0;
    queue<int>q;
    vector<bool>inQueue(n + 1, false);
    q.push(s);

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        inQueue[current] = false;
        // find longest path
        for(int i = 1; i <= n; i++) {
            if(map[current][i] && distancce[current] + 1 > distancce[i]) {
                distancce[i] = distancce[current] + 1;
                if(!inQueue[i]) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }
        }
    }
    int maxIndex = 1;
    for(int i = 1; i <= n; i++)
        if(distancce[i] > distancce[maxIndex])
            maxIndex = i;
    return maxIndex;
}

int main()
{
    int n;
    int case_index = 1;
    while(scanf("%d", &n) != EOF && n != 0) {
        int s;
        scanf("%d", &s); // source

        int p,q;
        bool map[105][105] = {false};
        while(scanf("%d %d", &p, &q) != EOF 
              && p != 0 && q != 0)
            map[p][q] = true;
        vector<int>distance(n+1, 0);

        int final_index = longestPath(map, distance, s, n);
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n"
               , case_index, s, distance[final_index], final_index);
        case_index ++;
    }
    return 0;
}

