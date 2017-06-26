#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int length;
	int placeholder;
	int counter = 1;
	while(true){
		scanf("%d", &length);
		if(length ==0){
			break;
		}
		int numzeroes =0;
		for(int i=0; i<length; i++){
			scanf("%d", &placeholder);
			if(placeholder ==0){
				numzeroes++;
			}
		}

		printf("Case %d: %d\n", counter++, length - 2*numzeroes);
	}
}