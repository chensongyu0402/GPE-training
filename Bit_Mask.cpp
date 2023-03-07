/*
    Keyword: None
    source1(answer): https://yuihuang.com/uva-10718/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    unsigned int n, l, u, ans;
    while(cin >> n >> l >> u) {
        ans = 0;
        for(int i = 31; i >= 0; i--) {
            if((ans | (1<<i)) > u)continue;
            if((ans | (1<<i)) <= l || !(n&(1<<i)))
                ans |= (1<<i);
        }
        cout << ans << endl;
    }
    return 0;
}