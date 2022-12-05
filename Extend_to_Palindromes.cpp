/*
    Keyword: KMP, string
    source1(answer): https://timbian.wordpress.com/2015/02/23/uva-11475-extend-to-palindrome/
*/
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

#define LEN 100000
int f[LEN + 10];

void faliure(string p)
{
    int i,j;
    f[0] = -1;
    for(i = 1,j = -1; p[i]; i++) {
        while(j >= 0 && p[j + 1] != p[i])
            j = f[j]; // tricky
        if(p[j + 1] == p[i])
            j++;
        f[i] = j;
    }
}

int KMP(string s, string p)
{
    int i,j;
    faliure(p);
    for(i = 0,j = -1; s[i]; i++) {
        while(j >= 0 && p[j + 1] != s[i])
            j = f[j];
        if(p[j + 1] == s[i])
            j++;
    }
    return j;
}

int main()
{
    while(1) {
        string s,p;
        cin >> s;
        int len = s.length();
        for(int j = len -1; j >= 0; j--)
            p += s[j];
        int cut = KMP(s, p);
        cout << s;
        for(int i = cut + 1; i <= len; i++)
            cout << p[i];
        cout << endl;
    }
    return 0;
}