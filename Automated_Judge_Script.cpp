/*
    Keyword: None
    source1(answer): https://github.com/morris821028/UVa/blob/master/volume101/10188%20-%20Automated%20Judge%20Script.cpp
*/
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
char A[105][150], B[105][150], bufA[15000], bufB[15000];
int n,m;

int AC()
{
    if(n!=m)
        return 0;
    for(int i = 0; i < m; i++)
        if(strcmp(A[i], B[i]))
            return 0;
    return 1;
}

int PE()
{
    int idxA = 0, idxB = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; A[i][j]; j++) {
            if(A[i][j] >= '0' && A[i][j] <= '9')
                bufA[idxA++] = A[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; B[i][j]; j++) {
            if(B[i][j] >= '0' && B[i][j] <= '9')
                bufB[idxB++] = B[i][j];
        }
    }
    bufA[idxA] = '\0';
    bufB[idxB] = '\0';
    return !strcmp(bufA,bufB);
}

int judge()
{
    if(AC())return 1;
    if(PE())return 2;
    return 3;
}

int main()
{
    int cases = 0;
    while(scanf("%d", &n) != EOF) {
        if(n == 0)break;
        cin.ignore();
        for(int i = 0; i < n; i++)
            gets(A[i]);
        scanf("%d", &m);
        cin.ignore();
        for(int i = 0; i < m; i++)
            gets(B[i]);
        int flag = judge();
        if(flag == 1)
            printf("Run #%d: Accepted\n", ++cases);
        else if(flag == 2)
            printf("Run #%d: Presentation Error\n", ++cases);
        else
            printf("Run #%d: Wrong Answer\n", ++cases);
    }
    return 0;
}