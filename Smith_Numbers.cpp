/*
    Keyword: prime
    source1(answer): https://knightzone.studio/2014/10/12/2284/uva%EF%BC%9A10042%EF%BC%8Dsmith-numbers/
*/
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

const float ERROR = 1e-9;

int digitSum(int n)
{
    int sum = 0;
    while(n > 0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main()
{
    // composite array
    int composite[50000] = {true, true, false}; // since sqrt(1e9)
    for(int i = 2; i < 50000; i++) {
        if(!composite[i]) {
            for(int j = i + i; j < 50000; j+=i)
                composite[j] = true;
        }
    }

    int testcase;
    while(scanf("%d", &testcase) != EOF) {
        int n;
        for(int i = 0; i < testcase; i++) {
            scanf("%d", &n);
            int simith_num = n + 1;
            while(1) {
                int left_num = 0, right_num = 0; // 左式 and 右式
                int temp = simith_num;
                int sqrt_num = (int)(sqrt(temp) + ERROR); //減少計算
                // 質因數分解
                for(int j = 2; j <= sqrt_num && temp > 1; j++) {
                    if(!composite[j]) {
                        while(temp%j == 0) {
                            temp /= j;
                            right_num += digitSum(j);
                        }
                    }
                }
                // 做最後的計算
                if(temp != simith_num) {
                    if(temp > 1)right_num += digitSum(temp);
                    left_num = digitSum(simith_num);
                    if(left_num == right_num)break;
                }
                simith_num ++;
            }
            printf("%d\n", simith_num);
        }
    }
    return 0;
}