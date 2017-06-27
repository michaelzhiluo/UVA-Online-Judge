#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
	char line[1000];
	fgets(line, 1000, stdin);
	int TC = stoi(line);
	while(TC--){
		fgets(line, 1000, stdin);
		int count =0;
		for(int i=0; i<strlen(line); i++){
			if(line[i] == 'M'){
				count++;
			}else if(line[i] == 'F'){
				count--;
			}
		}
		printf(count ==0 && strlen(line)>3 ? "LOOP\n" : "NO LOOP\n");
	}
	return 0;
}