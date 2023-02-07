/*
    Keyword: DP
    source1(answer): https://knightzone.studio/2020/04/28/4856/uva%EF%BC%9A10465%EF%BC%8Dhomer-simpson/
*/
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int m, n, t;
    while(scanf("%d%d%d", &m, &n, &t) != EOF) {
        int maxBT = max(m,n); // max burger time
        int minBT = min(m,n); // min burger time

        int maxBC = t / minBT; // max burger count
        int remainTime = t - maxBC * minBT;
        for(int i = maxBC - 1; i >= 0 && remainTime != 0; i--) {
            int currentTime = t - i * minBT;
            int anotherBC = currentTime / maxBT;
            currentTime -= anotherBC * maxBT;
            if(currentTime < remainTime) {
                maxBC = i + anotherBC;
                remainTime = currentTime;
            }
        }
        printf("%d", maxBC);
        if(remainTime > 0)printf(" %d", remainTime);
        printf("\n");
    }
    return 0;
}