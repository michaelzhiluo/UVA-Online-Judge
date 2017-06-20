#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	//FILE *in = fopen("input.txt", "r");
	//FILE *out = fopen("output.txt", "w");

	long int TC;
	scanf("%ld", &TC);
	while(TC--){
		long int numstores;
		scanf("%ld", &numstores);
		vector<int> positions(numstores);
		long int min =numeric_limits<int>::max(); 
		long int max =numeric_limits<int>::min(); 
		for(int i=0; i<positions.size(); i++){
			scanf("%ld", &numstores);
			if(numstores < min){
				min = numstores;
			}
			if(numstores > max){
				max = numstores;
			}
		}
		cout << 2*(max - min) << endl;
	}
	return 0;
}