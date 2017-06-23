#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	scanf("%d", &TC);
	int low, high;
	for(int j=1; j<=TC; j++){
		low =0; high =0;
		int numwalls =0;
		scanf("%d", &numwalls);
		int walls[numwalls];
		scanf("%d", &walls[0]);
		for(int i=1; i<numwalls; i++){
			scanf("%d", &walls[i]);	
			if(walls[i] > walls[i-1]){
				high++;
			}else if(walls[i] < walls[i-1]){
				low++;
			}		
		}
		printf("Case %d: %d %d\n", j, high, low);
	}
	
}