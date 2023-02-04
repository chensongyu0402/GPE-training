/*
    Keyword: None
    source1(answer): https://yuihuang.com/zj-d048/
*/
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int T, hh, mm;
    string s;
    cin >> T;
    while(T--) {
        cin >> s;
        int minutes = (s[0] - '0')*600 + (s[1] - '0')*60 + (s[3] - '0')*10 + (s[4] - '0');
        while(1) {
            minutes++;
            if(minutes >= 1440)minutes = 0;
            hh = minutes / 60;
            mm = minutes % 60;
            if(hh == 0) {
                if(minutes < 10 || minutes/10 == minutes%10)break; // 01 or 11 ...
            }
            else if(hh < 10) {
                if(hh == mm%10)break;
            } else {
                if((hh / 10 == mm % 10) && (hh % 10 == mm / 10))break;
            }
        }
        printf("%02d:%02d\n", hh, mm);
    }
    return 0;
}
