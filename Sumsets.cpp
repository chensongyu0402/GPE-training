#include<stdlib.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdbool.h>
using namespace std;

int main()
{
    while(1){
        int num;
        cin >> num;
        if(num == 0)
            break;
        vector<int> arr;
        int ans;
        bool solution = false;
        for(int i = 0; i < num; i++) {
            int element;
            cin >> element;
            arr.push_back(element);
        }
        sort(arr.begin(), arr.end());
        // brute force method
        for(int i = num - 1; i > 2; i--) {
            for(int j = 0; j < i - 2; j++) {
                for(int k = 1; k < i - 1; k++) {
                    for(int l = 2; l < i; l++)
                        if(arr[i] == (arr[j] + arr[k] + arr[l])) {
                            ans = arr[i];
                            solution = true;
                        }
                }
            }
        }
        if(solution == false)
            cout << "no solution" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}