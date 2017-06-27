#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int positive_modulo(int a, int b) {
    return (a%b+b)%b;
}

int main(){
	int TC, index;
	scanf("%d", &TC);
	char line[100001];
	int memory[100];
	for(int l=1; l<=TC; l++){
		for(int i=0; i<100; i++){memory[i] =0;}
		scanf("%s", &line);
		index =0;
		for(int i=0; i<strlen(line); i++){
			if(line[i]== '+'){
				memory[index] = positive_modulo(memory[index]+1, 256);
			}else if(line[i] == '-'){
				memory[index] = positive_modulo(memory[index]-1, 256);
			}else if(line[i] == '<'){
				index  = positive_modulo(index-1, 100);
			}else if(line[i] == '>'){
				index = positive_modulo(index+1, 100);
			}
		}
		printf("Case %d:", l);
		for(int i=0; i<100; i++){ printf(" %02X", memory[i]);}
		printf("\n");
	}
	return 0;
}