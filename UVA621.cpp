#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
	char word[10000];
	int TC;
	scanf("%d", &TC);

	while(TC--){
		scanf("%s", &word);
		int length = strlen(word);
		if(strcmp(word, "1")==0 || strcmp(word, "4")==0 || strcmp(word, "78")==0){
			printf("+\n");
		}else if(length >=2 && word[length - 1] == '5' && word[length-2] == '3'){
			printf("-\n");
		}else if(length >=2 && word[0] == '9' && word[length-1] == '4'){
			printf("*\n");
		}else if(length >=3 && word[0] == '1' && word[1] == '9' && word[2] == '0'){
			printf("?\n");
		}else{
			printf("+\n");
		}
	}


}