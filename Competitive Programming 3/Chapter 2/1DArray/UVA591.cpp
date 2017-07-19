#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
	int length, counter =1;
	while(true){
		scanf("%d", &length);
		if(!length){break;}
		int wall[length];
		int sum =0;
		for(int i=0; i<length; i++){
			scanf("%d", &wall[i]);
			sum+=wall[i];
		}
		int average = sum/length;
		sum =0;
		for(int i=0; i<length; i++){
			sum += abs(wall[i] -average);
		}
		printf("Set #%d\n", counter);
		printf("The minimum number of moves is %d.\n\n", sum/2);
		counter++;
	}
    return 0;
}