#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	int salaries[3];
	long int min, max;
	scanf("%d", &TC);
	for(int j=1; j<=TC; j++){
		min = 20000;
		max = -20000;
		scanf("%d %d %d", salaries, salaries+1, salaries+2);
		for(int i: salaries){
			if(i < min){
				min = i;
			}
			if(i > max){
				max = i;
			}
		}
		for(int i: salaries){
			if(i!=min && i!= max){
				printf("Case %d: %d\n", j, i);
				break;
			}
		}

	}
}

