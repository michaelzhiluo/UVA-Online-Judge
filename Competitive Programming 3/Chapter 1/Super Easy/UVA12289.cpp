#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// dumb and actual must be same length btw
int numdifferences(char* dumb, char* actual){
	int diff =0;
	for(int i=0; i< strlen(dumb); i++){
		if(dumb[i] != actual[i]){
			diff++;
		}
	}
	return diff;
}


int main(){
	int TC;
	char stupidkid[10];
	scanf("%d", &TC);

	while(TC--){
		scanf("%s", stupidkid);
		if(strlen(stupidkid) ==3){
			if(numdifferences(stupidkid, "one")<=1){
				printf("1\n");
			}else if(numdifferences(stupidkid, "two")<=1){
				printf("2\n");
			}
		}else{
			printf("3\n");
		}

	}



}

