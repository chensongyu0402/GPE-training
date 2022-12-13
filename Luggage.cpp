/*
    Keyword: DP, 0/1 backage
    source1(answer): https://knightzone.studio/2020/04/16/4816/uva%EF%BC%9A10664%EF%BC%8Dluggage/
*/

#include<stdlib.h>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;

int main()
{
    int m;
    while(scanf("%d ",&m)!= EOF) { //一定要空白，不然會出錯
        for(int case_i = 1; case_i <= m; case_i++) {
            string input;
            getline(cin, input);
            stringstream ss(input);

            vector<int>weights;
            int weight;
            int sum = 0;

            while(ss >> weight) {
                weights.push_back(weight);
                sum += weight;
            }

            if(sum % 2 == 1) {
                printf("NO\n");
                continue;
            }

            vector<bool>dp(sum + 1, false);
            dp[0] = true;
            for(int i = 0; i < weights.size(); i++) {
                for(int j = sum; j >= weights[i]; j--) {
                    if(dp[j - weights[i]]) {
                        dp[j] = true;
                    }
                }
            }   
            if(dp[sum / 2])
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}