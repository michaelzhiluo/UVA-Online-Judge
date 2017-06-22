#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int milescost(int& amount){
	return 10*(amount/30 + 1);
}

int juicecost(int& amount){
	return 15*(amount/60 + 1);
}


int main(){
	int TC;
	scanf("%d", &TC);
	int mcost, jcost, placeholder, durations;
	for(int i=1; i<=TC; i++){
		mcost =0; jcost =0;
		scanf("%d", &durations);
		for(int j=0; j<durations; j++){
			scanf("%d", &placeholder);
			mcost += milescost(placeholder);
			jcost += juicecost(placeholder);
		}
		printf("Case %d: ", i);
		if(mcost < jcost){
			printf("Mile %d\n", mcost);
		}else if(mcost > jcost){
			printf("Juice %d\n", jcost);
		}else{
			printf("Mile Juice %d\n", mcost);
		}
	}
	
}