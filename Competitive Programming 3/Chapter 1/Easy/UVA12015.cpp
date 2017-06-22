#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC, relev;
	vector<string> names;
	string placeholder[10];
	scanf("%d", &TC);
	for(int i=1; i<=TC; i++){
		int max = -10000;
		names.clear();
		for(int j=0; j<=9; j++){
			cin >> placeholder[j] >> relev;
			if(relev > max){
				names.clear();
				max = relev;
				names.push_back(placeholder[j]);
			}else if(relev == max){
				names.push_back(placeholder[j]);
			}
		}
		printf("Case #%d:\n", i);
		for(int j=0; j<names.size(); j++){
			printf( "%s\n", names[j].c_str());
		}

	}
}