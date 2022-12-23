/*
    Keyword: 
    source1(chinese): http://web.kshs.kh.edu.tw/academy/luckycat/homework/q10110.htm
    source2(answer): http://programming-study-notes.blogspot.com/2014/02/uva-10110-light-more-light.html
*/
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
    unsigned int n; // since  < 2^32 - 1
    while(scanf("%u", &n) != EOF) {
        if(!n)break;
        unsigned int a = sqrt(n);
        if(a * a == n)
            printf("yes\n");
        else
            printf("no\n"); 
    }
    return 0;
}