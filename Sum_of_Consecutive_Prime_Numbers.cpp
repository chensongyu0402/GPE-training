/*
    Keyword: None
    source1(answer): 
*/
#include<stdlib.h>
#include<vector>
#include<iostream>
using namespace std;

const int max_n = 10000+5;
int pt[max_n];
vector<int>p;

int main()
{
    // prime table
    for(int i = 2; i < max_n; i++) {
        if(pt[i] == 0) {
            for(int j = i + i; j < max_n; j += i)
                pt[j] = 1;
            p.push_back(i);
        }
    }

    int n;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        int count = 0;
        for(int i = 0; i < p.size(); i++) {
            int sum = 0;
            for(int j = i; j < p.size(); j++) {
                sum += p[j];
                if(sum == n) {
                    count ++;
                    break;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}