#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	//FILE *in = fopen("input.txt", "r");
	//FILE *out = fopen("output.txt", "w");

	long int TC;
	
	long int a,b;
	while(scanf("%d", &TC) ==1){
		for(long int i=0; i< TC; i++){
			scanf("%ld %ld", &a, &b);
			if(a>b){
				printf(">\n");
			}else if(a<b){
				printf("<\n");
			}else{
				printf("=\n");
			}
		}
	}
	return 0;
}