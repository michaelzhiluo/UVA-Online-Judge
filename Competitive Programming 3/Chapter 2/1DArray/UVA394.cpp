#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct MYARRAY{
    int dim;
    int bytes;
    vector<long int> low;
    vector<long int> high;
    vector<long int> c;
    long int c0;
};

map<string, MYARRAY> arrays;

int main(){
    ios_base::sync_with_stdio(0);
    int numarrays, numtestcases;
    string name;
    cin >> numarrays >> numtestcases;
    for(int i=0; i<numarrays; i++){
        MYARRAY temp;
        cin >> name >> temp.c0 >> temp.bytes >> temp.dim;  
        long int lower[temp.dim];
        long int higher[temp.dim];
        for(int j=0; j<temp.dim; j++){
            cin >> lower[j] >>higher[j];
        }
        temp.low = vector<long int>(lower, lower + temp.dim);
        temp.high = vector<long int>(higher, higher + temp.dim);
        temp.c = vector<long int>(temp.dim);
        temp.c[temp.dim-1] = temp.bytes;
        for(int j=temp.dim-2; j>=0; j--){
            temp.c[j] = temp.c[j+1]*(temp.high[j+1] - temp.low[j+1] + 1);
        }        
        for(int j= temp.dim - 1; j>=0; j--){
            temp.c0 -= temp.c[j]*temp.low[j];
        }
        arrays[name] = temp;
    }
    long int ans;
    for(int i=0; i<numtestcases; i++){
        cin >> name;
        MYARRAY& temp = arrays[name]; 
        int ii[temp.dim];
        ans =temp.c0;
        printf("%s[", name.c_str());    
        for(int j=0; j<temp.dim; j++){
            cin >> ii[j];
            if(j!=temp.dim-1){
                printf("%d, ", ii[j]);
            }else{
                printf("%d", ii[j]);
            }
            ans+= temp.c[j]*ii[j];
        }
        printf("] = %ld\n", ans);
    }
    return 0;
}