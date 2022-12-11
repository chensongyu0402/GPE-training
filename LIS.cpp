/*
    Keyword: Longest Increasing Subsequence, Leetcode
    source1(answer): https://leetcode.com/problems/longest-increasing-subsequence/
*/
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(vector<int>&nums)
{
    vector<int>dp;
    dp.push_back(nums[0]);
    for(int n : nums) {
        auto j = lower_bound(dp.begin(), dp.end(), n); // address
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
    vector<int>nums;
    while(scanf("%d",&n) != EOF) {
        int element;
        nums.clear();
        for(int i = 0; i < n; i++) {
            scanf("%d",&element);
            nums.push_back(element);
        }
        int ans = LIS(nums);
        printf("%d\n",ans);
    }
    return 0;
}