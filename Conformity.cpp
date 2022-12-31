/*
    Keyword: None
    source1(answer): https://knightzone.studio/2020/05/09/4944/uva%EF%BC%9A11286%EF%BC%8Dconformity/
*/
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

string join(const vector<string>&strings)
{
    string result;
    for(int i = 0; i < strings.size(); i++)
        result += strings[i];
    return result;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        // 用 key 與 count 去計算
        map<string, int> courseCombinationCount;
        for(int i = 0; i < n; i++) {
            vector<string>courses(5);
            for(int j = 0; j < 5; j++) {
                cin >> courses[j];
            }
            sort(courses.begin(), courses.end());
            ++ courseCombinationCount[join(courses)];
        }
        // 如果數量一樣多的話，會直接全部加起來
        int maxStudents = 0;
        int totalStudents = 0;
        for(map<string, int>::iterator it = courseCombinationCount.begin();
            it != courseCombinationCount.end();
            it ++) {
                if(it -> second > maxStudents) {
                    maxStudents = it -> second;
                    totalStudents = it -> second;
                }else if(it -> second == maxStudents) {
                    totalStudents += it -> second;
                }
            }
        printf("%d\n", totalStudents);
    }
    return 0;
}