/*
    Keyword: DP
    source1(answer): https://www.pinghenotes.com/UVa-10003-Cutting-Sticks/
*/
#include<stdlib.h>
#include<memory.h>
#include<iostream>
using namespace std;

int dp[52][52];
int woods[52];

int main()
{
    int L,N;
    while(cin >> L , L && cin >> N) {
        memset(dp, 0, sizeof(dp));
        memset(woods, 0, sizeof(woods));

        for(int i = 1; i <= N; i++)
            cin >> woods[i];
        woods[++N] = L;

        for(int r = 2; r <= N; r++) {
            for(int b = 0; b < N; b++) {
                int e = b + r;
                if(e > N)break;
                dp[b][e] = INT_MAX;
                for(int c = b + 1; c < e; c++) {
                    int temp = dp[b][c] + dp[c][e] + woods[e] - woods[b];
                    dp[b][e] = min(dp[b][e], temp);
                }
            }
        }

        cout << "The minimum cutting is " << dp[0][N] << endl;
    }
    return 0; 
}