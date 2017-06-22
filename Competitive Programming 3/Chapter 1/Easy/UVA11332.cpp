#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sumdigits(long int& number){
	long int sum =0;
	while(number!=0){
		sum += number%10;
		number/=10;
	}
	number = sum;
}

int main(){
	long int num;
	while(true){
		scanf("%ld", &num);
		if(num==0){break;}
		while(num >=10){
			sumdigits(num);
		}
		printf("%d\n", num);
	}
}

