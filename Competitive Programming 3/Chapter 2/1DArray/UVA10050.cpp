#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC, days, p;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &days);
		scanf("%d", &p);
		int hartal[p];
		for(int i=0; i<p; i++){
			scanf("%d", &hartal[i]);
		}
		int counter =0;
		for(int i=1; i<=days; i++){
			if(i%7 == 6 || i%7==0){ continue;}
			for(int j=0; j<p; j++){
				if(i%hartal[j] ==0){
					counter++;
					break;
				}
			}
		}
		printf("%d\n", counter);

	}
    return 0;
}