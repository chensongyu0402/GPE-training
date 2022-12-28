/*
    Keyword: Longest Increasing Subsequence (LIS), DP
    source1(answer): https://knightzone.studio/2015/03/15/2715/uva%EF%BC%9A10131%EF%BC%8Dis-bigger-smarter/
*/
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int NO_MEMBER = -1;

struct Elephant {
    int id;
    int weight;
    int IQ;
};

bool cmpWeight(Elephant e1, Elephant e2)
{
    return e1.weight <= e2.weight;
}

void printLIS(const vector<Elephant> &elephants,
              const vector<int> &LISprev,
              int index)
{
    if(LISprev[index] != NO_MEMBER)printLIS(elephants, LISprev, LISprev[index]); // 判斷需不需要往前找
    printf("%d\n", elephants[index].id);
}

int main()
{
    vector<Elephant> elephants;
    Elephant e;
    while(scanf("%d%d", &(e.weight), &(e.IQ)) != EOF) {
        // if(e.weight == 0 && e.IQ == 0)break;
        e.id = elephants.size() + 1;
        elephants.push_back(e);
    }
    
    sort(elephants.begin(), elephants.end(), cmpWeight);
    
    vector<int>LISlength(elephants.size(), 1);
    vector<int>LISprev(elephants.size(), NO_MEMBER);
    
    int maxLen = 0, maxIndex = NO_MEMBER;
    for(int i = 0; i < elephants.size(); i++) {
        for(int j = i + 1; j < elephants.size(); j++) {
            if(elephants[i].weight < elephants[j].weight &&
               elephants[i].IQ > elephants[j].IQ) {
                if(LISlength[i] + 1 > LISlength[j])
                    LISlength[j] = LISlength[i] + 1;
                    LISprev[j] = i;
               }
        }
        if(LISlength[i] > maxLen) {
            maxLen = LISlength[i];
            maxIndex = i;
        }  
    }

    printf("%d\n", maxLen);
    printLIS(elephants, LISprev, maxIndex);
    // system("pause");
    return 0;
}