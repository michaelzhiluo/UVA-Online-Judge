#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		long int temp;
		scanf("%ld", &temp);
		temp = (63*temp + 7492)*5 - 498;
		temp  = abs((temp/10)%10);
		printf("%d\n", temp);
	}
}

