#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	scanf("%d", &TC);
	char command[10];
	long int donations =0;
	int k =0;
	while(scanf("%s", command) != EOF){
		if(strcmp(command, "donate")){
			scanf("%d", k);
			donations+=k;
		}else{
			printf("%d\n", donations);
		}
	}
}

