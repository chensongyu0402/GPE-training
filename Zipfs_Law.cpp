/*
    Keyword: None
    source1(answer): https://github.com/Hikari9/UVa/blob/master/10126%20-%20Zipf's%20Law.cpp
*/
#include<stdlib.h>
#include<map>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

map<string, int> m;
map<string, int>:: iterator it;
string buf, word;
bool found, f = false;

int main()
{
    int n;
    while(cin >> n) {
        if(f)printf("\n");
        f = true;
        m.clear();
        while(cin >> buf) {
            /*  How to use transform function in C++
                source1 : https://www.twblogs.net/a/5eee24844b16c91a28492f4d
                source2 : https://blog.csdn.net/fengbingchun/article/details/63252470
                source3 : https://vimsky.com/zh-tw/examples/usage/cpp-algorithm-transform-function-01.html
            */
            transform(buf.begin(), buf.end(), buf.begin(), ::tolower);
            if(buf == "endoftext")break;
            for(int i = 0; i < buf.size(); i++) {
                if(islower(buf[i])) { // 相當於確認是不是字母
                    word.clear();
                    do{
                        word.push_back(buf[i]);
                        i++;
                    }while(i < buf.length() && islower(buf[i]));
                    m[word]++;
                }
            }
            found = false;
            for(it = m.begin(); it != m.end(); it ++) {
                if(it->second == n) {
                    cout << it->first << endl;
                    found = true;
                }
            }

            if(found == false)
                cout << "There is no such word." << endl;
        }
    }
    return 0;
}