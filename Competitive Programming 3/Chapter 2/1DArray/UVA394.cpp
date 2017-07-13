#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct MYARRAY{
    long int base;
    int dim;
    int bytes;
    long int low[];
    long int high[];
    long int c[];
    long int c0;
};

map<string, MYARRAY> arrays;

int main(){
    ios_base::sync_with_stdio(0);
    int numarrays, numtestcases;
    string name;
    cin >> numarrays >> numtestcases;
    for(int i=0; i<numarrays; i++){
        cin >> name;
        MYARRAY temp;
        cin >> temp.base >> temp.bytes >> temp.dim; 
        long int lower[temp.dim];
        long int higher[temp.dim];
        temp.low = lower;
        temp.high = higher;
        for(int j=0; j<temp.dim; j++){
            cin >> temp.low[j] >>temp.high[j];
        }

        arrays[name] = temp;

    }
    return 0;
}