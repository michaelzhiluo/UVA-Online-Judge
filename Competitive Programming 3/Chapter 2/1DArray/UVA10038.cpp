#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){ 
   int n, works, num[3000], diff[3000];
   while(scanf("%d",&n) == 1){ 
      for(int i = 0; i < n; i++){
         scanf("%d",&num[i]);
         diff[i] = 0;        
      }
      works = n-1;
      for(int i = 0; i < works; i++)
         diff[abs(num[i]-num[i+1])] = 1;
      works = 1;
      for(int i = 1; i < n; i++){
         if(!diff[i]){
            works = 0;
            break;
         }
      }
      if(works)
         printf("Jolly\n");
      else 
         printf("Not Jolly\n");
   }
   return 0;
}