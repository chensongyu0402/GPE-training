/*
    Keyword: math
    source1(chinese): https://blog.csdn.net/mobius_strip/article/details/37757287
*/
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

int map[20] = {
    0,1,5,2,8,3,9,2,8,7,
	7,8,4,7,3,8,4,1,5,4};

int main()
{
    string str;
    while(cin >> str) {
        int len = str.length();
        if(len == 1 && str[0] == '0')
            break;
        int value = str[len - 1] - '0';
        if(len > 1)
            value += (str[len-2] - '0')*10;
        cout << (map[value%20]+value/20*4)%10 << endl;
    }
    return 0;
}