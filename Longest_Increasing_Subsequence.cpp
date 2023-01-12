/*
    Keyword: None
    source1(answer): Leetcode 300 Longest Increasing Subsequence
*/

#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int LIS(vector<int>&nums)
{
    vector<int>dp;
    dp.push_back(nums[0]);
    for(int n : nums) {
        auto j = lower_bound(dp.begin(), dp.end(), n);
        if(j == dp.end())
            dp.push_back(n);
        else
            *j = n;
    }
    return dp.size();
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        vector<int>nums;
        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }
        int ans = LIS(nums);
        printf("%d\n", ans);
    }
    return 0;
}
