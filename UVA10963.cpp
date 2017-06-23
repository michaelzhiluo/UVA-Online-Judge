#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	int length;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &length);
		bool works = true;
		int bottom[length];
		int up[length];
		for(int i=0; i<length; i++){
			scanf("%d %d", &bottom[i], &up[i]);
		}
		int gap;
		if(length !=0){
			gap = bottom[0] - up[0];
		}
		for(int i=1; i<length; i++){
			if(bottom[i] - up[i] != gap){
				works = false; break;
			}
		}
		printf(works ? "yes\n": "no\n");
		if(TC){
			printf("\n");
		}
	}	
}

