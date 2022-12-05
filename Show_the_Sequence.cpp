/*
    Keyword: recursive, string
    source1(answer): https://morris821028.github.io/2014/07/31/oj/uva/uva-997/
*/
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

long long a[125];
void sequence(char *s)
{
    int sign = 1, i, m = 0;
    char pos;
    // get operator and number
    for(i = 1; s[i]; i++) {
        if(s[i] == '-') sign = -1;
        else if(s[i] >= '0' && s[i] <= '9')
            m = m * 10 + (s[i] - '0');
        else {
            pos = s[i];
            break;
        }
    }
    m = sign * m;
    if(pos == '+') {
        sequence(s + i + 1);
        long long d = a[0]; // save old number
        a[0] = m;
        for(int j = 1; j < 50; j++) {
            long long t = a[j]; // save old number
            a[j] = a[j - 1] + d; // V_i = V_i + S_i-1
            d = t;
        }
    }
    else if(pos == '*') {
        sequence(s + i + 1);
        a[0] *= m;
        for(int j = 1; j < 50; j++)
            a[j] = a[j - 1] * a[j]; // V_i = V_i-1 + S_i
    }else {
        for(int j = 0; j < 50; j++)
            a[j] = m;
    }
}

int main()
{
    char s[1024];
    int n;
    while(cin >> s >> n) {
        for(int i = 0; i < 125; i++)
            a[0] = 0;
        sequence(s);
        for(int i = 0; i < n - 1; i++)
            cout << a[i] << " ";
        cout << a[n - 1] << endl;
    }
    system("pause");
    return 0;
}