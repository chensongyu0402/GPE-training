/*
    Keyword: None
    source1(answer): https://knightzone.studio/2016/07/23/3151/uva%EF%BC%9A793%EF%BC%8Dnetwork-connections/
*/
#include<stdlib.h>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int case_num;
    while(scanf("%d", &case_num) != EOF) {
        for(int i = 0; i < case_num; i++) {
            if(case_num >= 1)
                printf("\n");
            int num_c; // number of computers
            scanf("%d", &num_c);

            vector<int>connection(num_c + 1, 0);
            for(int j = 1; j <= num_c; j++)
                connection[j] = j;
            
            int right_ans = 0, err_ans = 0;
            string input;
            cin.ignore();
            while(getline(cin, input) && input != "") {
                stringstream ss(input);
                char type;
                int computer1, computer2;
                ss >> type >> computer1 >> computer2;

                if(type == 'c') { // 不斷的對所有點更新
                    int group1 = connection[computer1], group2 = connection[computer2];
                    for(int j = 1; j <= num_c; j++) {
                        if(connection[j] == group1 || connection[j] == group2)
                            connection[j] = min(group1, group2);
                    }
                }
                else if(type == 'q') {
                    if(connection[computer1] == connection[computer2])
                        right_ans ++;
                    else
                        err_ans ++;
                }
            }
            printf("%d,%d\n", right_ans, err_ans);
        }
    }
    return 0;
}