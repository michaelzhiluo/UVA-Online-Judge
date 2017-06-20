#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	//FILE *in = fopen("input.txt", "r");
	//FILE *out = fopen("output.txt", "w");

	int TC;
	scanf("%d", &TC);
	
	long a,b;
	while(TC--){
		scanf("%d %d", &a, &b);
		if((long)a>(long)b){
			cout << ">" << endl;
		}else if((long)a<(long)b){
			cout << "<" << endl;
		}else{
			cout << "=" << endl;
		}
	}
	return 0;
}