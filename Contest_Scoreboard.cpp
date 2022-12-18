/*
    Keyword: None
    source1(answer): https://knightzone.studio/2012/03/16/1483/uva%EF%BC%9A10258%EF%BC%8Dcontest-scoreboard/
    source2(chinese): http://web.kshs.kh.edu.tw/academy/luckycat/homework/q10258.htm
*/

#include<stdlib.h>
#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
using namespace std;

struct Team{
    bool join;
    int num;
    int score;
    int problem;
    int err[10];
};

bool compare(Team a, Team b)
{
    if(a.problem > b.problem)return true;
    if(a.problem < b.problem)return false;
    if(a.score < b.score)return true;
    if(a.score > b.score)return false;
    if(a.num < b.num)return true;
    return false;
}

int main()
{
    int caseNum;
    string entry;
    stringstream ss;
    Team team[105];
    int contestant, problem, time;
    char L;

    while(scanf("%d", &caseNum) != EOF) {
        getchar();
        getchar();

        for(int caseIndex = 0; caseIndex < caseNum; caseIndex++) {
            //initial
            if(caseIndex)printf("\n");
            for(int i = 0; i < 105; i++) {
                team[i].join = false;
                team[i].num = i;
                team[i].score = 0;
                team[i].problem = 0;
                memset(team[i].err, 0, sizeof(team[i].err));
            }

            while(getline(cin, entry) && entry != "") {
                ss.clear();
                ss.str(entry);
                ss >> contestant >> problem >> time >> L;

                team[contestant].join = true;
                if(team[contestant].err[problem] == -1)continue;
                if(L == 'C') {
                    team[contestant].score += time + team[contestant].err[problem] * 20;
                    team[contestant].problem ++;
                    team[contestant].err[problem] = -1;
                }
                else if(L == 'I') {
                    team[contestant].err[problem] ++;
                }
            }
            sort(team, team + 105, compare); //sort ans
            for(int i = 0; i < 105; i++) {
                if(team[i].join)
                    printf("%d %d %d\n", team[i].num, team[i].problem, team[i].score);
            }
        }
    }
    return 0;
}