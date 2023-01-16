/*
    Keyword: None
    source1(answer): https://kai-y.medium.com/uva-10057-a-mid-summer-nights-dream-ea0e5eb610dc
*/
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        vector<int>nums;
        int number;
        for(int i = 0; i < n; i++) {
            scanf("%d", &number);
            nums.push_back(number);
        }
        sort(nums.begin(), nums.end());

        // find the minimum median in the sequence
        int min_med = 0;
        int max_med = 0;
        if(n%2 == 0) {
            min_med = nums[n/2 - 1];
            max_med = nums[n/2];
        }else {
            min_med = nums[n/2];
            max_med = nums[n/2];
        }

        // find the amount of number equal to the median in the sequence
        int count = 0;
        for(int i = 0; i <nums.size(); i++) {
            if(nums[i] == min_med || nums[i] == max_med)
                count++;
        }

        // find the amount of possible different integer can be the median of sequence
        int possible_med = 0;
        if(n%2 == 0)
            possible_med = max_med - min_med + 1;
        else
            possible_med = 1;
        
        printf("%d %d %d\n", min_med, count, possible_med);
    }
    return 0;
}

