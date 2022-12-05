/*
    Keyword: mapping
    source1(answer): https://blog.csdn.net/metaphysis/article/details/6930611
*/
#include<stdlib.h>
#include<iostream>
#include<utility>
#include<vector>
using namespace std;

#define MAXN 100200

vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, -1}, {1, 0}, {0, 1}};
vector<pair<int,int>>ans (MAXN + 2000, {0,0});

int main()
{
    // create mapping table
    for(int i = 1, j = 1, k = 0; i < MAXN; i += j, j += 6, k++) {

        // The first part
        pair<int,int> node = {0,k};
        ans[i] = node;
        for(int m = k - 1; m >= 0; m--) {
            pair<int, int> node = {m, k - m};
            ans[i - m] = node;
        }

        // The second part
        int current = i;
        for(int m = 0; m < dir.size(); m++) {
            for(int n = 0; n < k; n++) {
                pair<int,int> node;
                node.first = ans[current].first + dir[m][0];
                node.second = ans[current].second + dir[m][1];
                ans[current + 1] = node;
                current ++;
            }
        }
    }

    int willi;
    while(cin >> willi)
        cout << ans[willi].first << " " << ans[willi].second << endl;
    return 0;
}