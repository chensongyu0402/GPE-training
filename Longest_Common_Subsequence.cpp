/*
    Keyword: None
    source1(answer): https://knightzone.studio/2012/03/27/1538/uva%EF%BC%9A10405%EF%BC%8Dlongest-common-subsequence/
*/
#include<stdlib.h>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int LCS(const string &a, const string &b)
{
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1));
    for(int i = 1; i < dp.size(); i++) {
        for(int j = 1; j < dp.back().size(); j++) {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp.back().back();
}

int main()
{   
    string s1, s2;
    while(getline(cin, s1)) {
        getline(cin, s2);
        int ans = LCS(s1, s2);
        printf("%d\n", ans);
    }
    return 0;
}