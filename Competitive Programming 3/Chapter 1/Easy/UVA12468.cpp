#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b;
	while(true){
		scanf("%d %d", &a, &b);
		if(a ==-1 && b==-1){
			break;
		}
		printf("%d\n", min(abs(a-b), 100 - abs(a-b)));
	}
}