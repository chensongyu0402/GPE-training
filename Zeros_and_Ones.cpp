/*
    Keyword: None
    source1(answer): 
*/
// Please note, this program passed with 2.949 s out of 3 max, so it is not very efficient...
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
   char s[1000005];
   int n, a, b, tmp;
   int caseCount = 1;
   bool valid;

   while(scanf("%s", s)) {
        
        printf("Case %d:\n", caseCount++);
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &a, &b);
            if(b < a) {
                tmp = a;
                a = b;
                b = tmp;
            }
            valid = true;
            for(int i = a; i < b; i++) {
                if(s[i] != s[i+1]) {
                    valid = false;
                    break;
                }
            }
            if(valid)
                printf("Yes\n");
            else
                printf("No\n");
        }
   }
   return 0;
}