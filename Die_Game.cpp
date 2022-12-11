/*
    Keyword: None
    source1(answer): https://missterhao.me/2020/03/21/%E3%80%90cpe%E3%80%91uva-10409-die-game-%E4%B8%80%E6%98%9F%E5%BF%85%E8%80%83%E9%A1%8C-by-c/
*/
#include<stdlib.h>
#include<iostream>
using namespace std;


void toEast(int *arr)
{
    int t = arr[0];
    arr[0] = arr[3];
    arr[3] = arr[1];
    arr[1] = arr[5];
    arr[5] = t;
}

void toWest(int *arr)
{
    int t = arr[0];
    arr[0] = arr[5];
    arr[5] = arr[1];
    arr[1] = arr[3];
    arr[3] = t;
}

void toNorth(int *arr)
{
    int t = arr[0];
    arr[0] = arr[4];
    arr[4] = arr[1];
    arr[1] = arr[2];
    arr[2] = t;
}

void toSouth(int *arr)
{
    int t = arr[0];
    arr[0] = arr[2];
    arr[2] = arr[1];
    arr[1] = arr[4];
    arr[4] = t;
}

int main()
{
    int times;
    while(cin >> times && times != 0) {
        // die --> {上, 下, 北, 西, 南, 東} <-> {1, 6, 2, 3, 5, 4}
        int dies[6] = {1, 6, 2, 3, 5, 4};
        while(times --) {
            string a = "";
            cin >> a;
            if(a == "north")
                toNorth(dies);
            if(a == "south")
                toSouth(dies);
            if(a == "west")
                toWest(dies);
            if(a == "east")
                toEast(dies);
        }
        cout << dies[0] << endl;
    }
    return 0;
}