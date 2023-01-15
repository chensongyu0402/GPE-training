/*
    Keyword: DFS, tree, graph, tree diameter
    source1(answer1): https://www.cnblogs.com/scau20110726/archive/2013/04/07/3003926.html
    source2(answer2): https://blog.csdn.net/tengfei461807914/article/details/47155673
*/
#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
#include<sstream>
#include<iostream>
using namespace std;

const int max_n = 10001;
int ans = 0;
vector<pair<int,int>> vp[max_n]; // 到 i (first) 村莊的 cost (second)

int DFS(int to, int from)
{
    int Araod = 0, tem; // Aroad 紀錄最大的 tem
    for(int i = 0; i < vp[to].size(); i++) {
        int go = vp[to][i].first;
        if(go != from) {
            tem = DFS(go, to) + vp[to][i].second; // 這裡的 cost 是最後才加的
            ans = max(ans, tem + Araod);
            Araod = max(tem, Araod);
        }
    }
    return Araod;
}

int main()
{
    int a, b, c;
    string s;
    while(!cin.eof()) {
        for(int i = 0; i < max_n; i++)
            vp[i].clear();
        ans = 0;
        getline(cin, s);
        while(s.length() > 0 && !cin.eof()) {
            stringstream ss;
            ss << s;
            ss >> a >> b >> c;
            vp[a].push_back(make_pair(b,c));
            vp[b].push_back(make_pair(a,c));
            getline(cin, s);
        }
        DFS(1,0);
        cout << ans << endl;
    }
    return 0;
}