/*
    Keyword: None
    source1(answer): 
*/
#include<stdlib.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    int t;
    while(scanf("%d", &t) != EOF) {
        while(t--) {
            int n;
            scanf("%d", &n);
            int position = 0;
            vector<int>instr(n,0);
            for(int i = 0; i < n; i++) {
                string instruction;
                cin >> instruction;
                if(instruction == "LEFT") {
                    instr[i] = -1;
                    position--;
                }else if(instruction == "RIGHT") {
                    instr[i] == 1;
                    position ++;
                }else {
                    cin >> instruction;
                    int index;
                    scanf("%d", &index);
                    instr[i] = instr[index - 1];
                    position += instr[i];
                }
            }
            printf("%d\n", position);
        }
    }
    return 0;
}