#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int numpeople, budget, numhotels, numweeks, mincost;
	while(scanf("%d %d %d %d", &numpeople, &budget, &numhotels, &numweeks)!=EOF){
		mincost = budget + 1;
		for(int i=0; i<numhotels; i++){
			int hotelcost;
			scanf("%d", &hotelcost);
			for(int j=0; j<numweeks; j++){
				int temp;
				scanf("%d", &temp);
				if(temp >= numpeople && hotelcost*numpeople < mincost){
					//cout << hotelcost << " " << numpeople << endl;
					mincost = hotelcost*numpeople;
				}
			}
		}
		if(mincost > budget){
			printf("stay home\n");
		}else{
			printf("%d\n", mincost);
		}		

	}
	
}
