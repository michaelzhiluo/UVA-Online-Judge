#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int answer(int xi, int xf, int stacklength){
	if(xi == xf){
		return stacklength;
	}
	int length =0, temp = xf;
	while(xf!=0){ length++; xf/=10;}
	return answer(temp, length, stacklength+1);
}


int main(){
	char line[1000001];
	while(scanf("%s", &line) && line[0]!='E'){
		printf(strlen(line) ==1 && line[0] == '1' ? "1\n" : "%d\n", answer(-1, strlen(line), 1));
	}
	return 0;
}