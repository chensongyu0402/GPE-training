/*
    Keyword: None
    source1(answer): https://knightzone.studio/2020/05/07/4905/uva%EF%BC%9A10905%EF%BC%8Dchildrens-game/
*/
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

bool compare(const string &a, const string &b)
{
    return a+b > b+a;
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF) {
        if(n == 0)break;
        vector<string>number; 
        for(int i = 0; i < n; i++) {
            string input;
            cin >> input;
            number.push_back(input);
        }
        sort(number.begin(), number.end(), compare);
        string output;
        for(int i = 0; i < number.size(); i++)
            output += number[i];
        cout << output << endl;
    }
    return 0;
}

