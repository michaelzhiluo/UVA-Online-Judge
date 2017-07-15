#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
    int numlines, left, right;
    char placeholder[100];
    while(true){
        scanf("%d", &numlines);
        getchar();
        if(!numlines){break;}
        int min = 100;
        int sum =0;
        for(int i=0; i<numlines; i++){
            gets(placeholder);
            int x =0;
            while(placeholder[x] == 'X' && placeholder[x]!= '\0'){
                x++;
            }
            left = x;
            while(placeholder[x] !='X' && placeholder[x] !='\0'){
                x++;
            }
            right = x;
            min = (right - left) < min ? (right-left) : min;
            sum += right - left;
        }
        printf("%d\n", sum - numlines*min);
    }
    return 0;
}