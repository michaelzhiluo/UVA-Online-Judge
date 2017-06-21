#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	scanf("%d", &TC);
	char command[10];
	long int donations =0;
	int k =0;
	while(TC--){
		scanf("%s", command);
		if(strcmp(command, "donate") ==0){
			scanf("%d", &k);
			donations+=k;
		}else{
			printf("%ld\n", donations);
		}
	}
}

