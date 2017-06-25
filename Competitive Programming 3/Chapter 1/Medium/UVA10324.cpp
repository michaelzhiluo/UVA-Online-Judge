#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    char seq[1000001];
    int TC, a, b, counter = 1;
    char cache;
    bool yes;
    while(scanf("%s", seq)!=EOF){
        printf("Case %d:\n", counter);
        scanf("%d", &TC);
        rekt:
        for(int i=0; i<TC; i++){
            yes = true;
            scanf("%d %d", &a, &b);
            if(a >b){ swap(a, b);}
            cache = seq[a];
            for(int i = a+1; i<=b; i++){
                if(seq[i]!=cache){ yes = false;}
            }
            printf(yes ? "Yes\n" : "No\n");
        }
        counter++;
    }

}