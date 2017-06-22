#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	scanf("%d", &TC);
	int lumberjacks[10];
	bool greater, works;
	printf("Lumberjacks:\n");
	for(int i=1; i<=TC; i++){
		greater = false;
		works = true;
		scanf("%d", &lumberjacks[0]);
		scanf("%d", &lumberjacks[1]);
		if(lumberjacks[1] >= lumberjacks[0]){
			greater = true;
		}

		for(int j=2; j<=9; j++){
			scanf("%d", &lumberjacks[j]);
			if((greater && lumberjacks[j] < lumberjacks[j-1]) || (!greater && lumberjacks[j] > lumberjacks[j-1])){
				works = false;
			}
		}
		if(works){
			printf("Ordered\n");
		}else{
			printf("Unordered\n");
		}


	}
}