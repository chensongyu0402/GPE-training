/*
    Keyword: stack(vector), string
    source1(answer): https://blog.csdn.net/mobius_strip/article/details/89512868
*/
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

vector<string>word_list;

int main()
{
    string buf;
    while(getline(cin, buf) && buf[0] != '0') {
        string s;
        for(int i = 0; buf[i]; i++) {
            if(isalpha(buf[i])) {
                s = "";
                while(isalpha(buf[i])) {
                    s += buf[i];
                    i++;
                }
                i --;
                word_list.push_back(s);
                cout << s;
            }
            else if(isdigit(buf[i])) {
                int value = 0;
                while(isdigit(buf[i])) {
                    value = value*10 + (buf[i] - '0');
                    i++;
                }
                s = word_list[word_list.size() - value];
                word_list.erase(word_list.end() - value);
                word_list.push_back(s);
                i --;
                cout << s;
            }else {
                cout << buf[i];
            }
        }
        puts("");    
    }
    return 0;
}