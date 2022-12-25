/*
    Keyword: Euler Circuit
    source1(answer): https://theriseofdavid.github.io/2022/03/05/UVa/UVa10203/
    source2(answer): https://github.com/c-deguzman/UVa-Solutions/blob/master/10203%20-%20Snow%20Clearing.cpp
*/

#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<sstream>
using namespace std;

int main()
{
    int testcase;
    double dist = 0;
    cin >> testcase;
    while(testcase --) {
        dist = 0;
        int x1, x2, y1, y2;
        cin >> x1 >> x2;

        string line;
        getline(cin, line);
        while(getline(cin, line)) {
            if(line.empty())break;
            stringstream ss(line);
            ss >> x1 >> y1 >> x2 >> y2;
            dist += hypot(double(x1 - x2), double(y1 - y2));
        }
        dist = dist / 1000; // m -> km
        double hour = dist * 2 / 20;
        int mm = (int)round(hour * 60);
        printf("%d:%02d\n", mm/60, mm%60);
        if(testcase)
            cout << endl;
    }
    //system("pause");
    return 0;
}
