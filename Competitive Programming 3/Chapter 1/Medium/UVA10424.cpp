#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sumofnumbers(int x){
    int sum =0;
    while(x!=0){
        sum+=x%10;
        x = x/10;
    }
    return sum;
}

int calculate(char* p){
    int total =0;
    for(int i=0; i<strlen(p); i++){
        int temp = (int)p[i];
        if(temp >=65 && temp <=90){
            total += temp - 'A' + 1;
        }else if(temp >= 97 && temp <= 122){
            total += temp - 'a' + 1;
        }
    }
    while(total >=10){
        total = sumofnumbers(total);
    }
    return total;

}



int main(){
    char a[100];
    char b[100];
    while(fgets(a, 100, stdin) != NULL){
        fgets(b, 100, stdin);
        int a1 = calculate(a); int b1 = calculate(b);
        printf("%.2f %%\n", 100*((double)min(a1, b1))/max(a1, b1));
    }

}