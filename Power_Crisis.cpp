/*
    Keyword: Josephus problem, recursive
    source1(Josephus problem): https://www.geeksforgeeks.org/josephus-problem/
    source2(answer): https://knightzone.studio/2012/03/25/1522/uva%EF%BC%9A151%EF%BC%8Dpower-crisis/
*/
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

int Josh(vector<int>person, int k, int index)
{
    // The final person
    if(person.size() == 1) {
        // cout << person[0] << endl;
        return person[0];
    }
    // Kill person
    index = ((index + k)%person.size());
    person.erase(person.begin() + index);

    // The next person
    return Josh(person, k, index);
}
/*
int main_for_Josephus()
{
    int n; int k; // n is number of people, k is skipped number
    cin >> n;
    cin >> k;
    k --; // k th person will be killed
    vector<int> person;
    for(int i = 1; i <= n; i++)
        person.push_back(i);
  
    Josh(person, k, 0);
    system("pause");
}*/

/*
    method 1
    space complexity and time complexity is more than method 2
    This method is similar to method 2. 
*/
int method1() // power crisis
{
    while(1) {
        int num;
        cin >> num;
        if(num == 0)
            break;
        for(int k = 1; k <= num; k++) {
            vector<int> person;
            for(int i = 1; i <= num; i++)
                person.push_back(i);
            person.erase(person.begin() + 0);
            if(Josh(person, k-1, 0) == 13)
                cout << k << endl;
        }
    }
    return 0;
}

// method2
int main()
{
    int N, m;
    while(1) {
        cin >> N;
        if(N == 0)
            break;
        N --;
        for(m = 1; m <= N; m++) {
            int index = 0; //index is address not person number
            for(int i = 1; i <= N; i++)
                index = (index + m)%i;
            if(index == 11)
                break;
        }
        cout << m << endl;
    }
}