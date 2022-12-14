/*
    Keyword: None
    source1(answer): https://knightzone.studio/2019/04/21/4319/uva%EF%BC%9A10533%EF%BC%8Ddigit-primes/
*/
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

struct Number{
    bool isComposite;
    int total; // total Digit Prime Count to this number
};

int bitSum(int number)
{
    int sum = 0;
    while(number > 0) {
        sum += number%10;
        number /= 10;
    }
    return sum;
}

int main()
{
    const int TOTAL_NUMBER = 1000000;
    vector<Number>num(TOTAL_NUMBER,Number{false, 0});
    int n;

    for(int i = 2; i < TOTAL_NUMBER; i++) {
        // is composite
        if(num[i].isComposite) {
            num[i].total = num[i - 1].total;
            continue;
        }
        // find composite
        for(int j = i + i; j < TOTAL_NUMBER; j+= i)
            num[j].isComposite = true;
        // prime number and compute Digit Prime Count
        if(num[bitSum(i)].isComposite)
            num[i].total = num[i - 1].total;
        else
            num[i].total = num[i - 1].total + 1;
    }

    while(scanf("%d", &n) != EOF) {
        for(int case_index = 1; case_index <= n; case_index++) {
            int t1, t2;
            scanf("%d %d", &t1, &t2);
            printf("%d\n",num[t2].total - num[t1 - 1].total);
        }
    }
    return 0;
}
