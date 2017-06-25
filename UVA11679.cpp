#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	int numbanks, numdebts;
	up:
	while(true){
		scanf("%d %d", &numbanks, &numdebts);
		if(numbanks ==0 && numdebts ==0){ break;}
		long int reserves[numbanks];
		for(int i=0; i<numbanks; i++){scanf("%ld", &reserves[i]);}
		int from, to; 
		long int amount;
		for(int i=0; i<numdebts; i++){
			scanf("%d %d %ld", &from, &to, &amount);
			reserves[from-1] -= amount;
			reserves[to-1] +=amount;
		}

		for(int i=0; i<numbanks; i++){
			if(reserves[i]<0){
				printf("N\n");
				goto up;
			}
		}
		printf("S\n");

	}
}

