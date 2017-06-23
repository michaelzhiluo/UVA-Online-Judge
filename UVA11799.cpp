#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	scanf("%d", &TC);
	int n;
	int max;
	int placeholder;
	for(int i=1; i<=TC; i++){
		max =0;
		scanf("%d", &n);
		for(int j=0; j<n; j++){
			scanf("%d", &placeholder);
			if(placeholder > max){
				max = placeholder;
			}
		}
		printf("Case %d: %d\n", i, max);

	}
}