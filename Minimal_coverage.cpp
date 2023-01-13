/*
    Keyword: greedy
    source1(answer): https://knightzone.studio/2012/04/06/1689/uva%EF%BC%9A10020%EF%BC%8Dminimal-coverage/
*/
#include<stdlib.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<iostream>
using namespace std;

// pair: first -> start, second -> end
bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first < b.first)
        return true;
    else
        return false;
}

int main()
{
    int testCase;
    int temp, left, right, M;
    while(scanf("%d", &testCase) != EOF) {
        for(int i = 0; i < testCase; i++) {
            if(i)printf("\n");

            scanf("%d", &M);
            vector<pair<int,int>>lines, ans;
            pair<int,int>input;
            while(scanf("%d%d", &input.first, &input.second)!= EOF) {
                if(input.first == 0 && input.second == 0)break;
                lines.push_back(input);
            }
            sort(lines.begin(), lines.end(), cmp);

            left = 0, right = 0;
            for(int j = 0; j < lines.size(); j++) {
                int temp = -1;
                for(; j < lines.size() && lines[j].first <= left; j++) {
                    if(lines[j].second >= right) {
                        right = lines[j].second;
                        temp = j;
                    }
                }
                if(temp == -1)break;
                ans.push_back(lines[temp]);
                if(right >= M)break;
                left = right;
                j --; // 因為會多加1
            }

            if(right < M) {
                printf("0\n");
                continue;
            }
            printf("%d\n", ans.size());
            for(int k = 0; k < ans.size(); k++)
                printf("%d %d\n", ans[k].first, ans[k].second);
        }
    }
    system("pause");
    return 0;
}
