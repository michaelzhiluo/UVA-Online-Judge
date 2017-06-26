#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
	int length;
	foo:
	while(true){
		scanf("%d", &length);
		if(length ==0){ break; }
		vector<int> restaurants, drugstores;
		int mindistance = length;
		char line[length];
		scanf("%s", line);
		for(int i=0; i<length; i++){
			if(line[i] == '.'){
				continue;
			}
			else if(line[i] == 'R'){
				restaurants.push_back(i);
			}else if(line[i] == 'D'){
				drugstores.push_back(i);
			}else if(line[i] == 'Z'){
				printf("0\n"); goto foo;
			}
		}
		for(int i=0; i<drugstores.size(); i++){
			for(int j=0; j<restaurants.size(); j++){
				if(abs(drugstores[i] - restaurants[j]) < mindistance){
					mindistance = abs(drugstores[i] - restaurants[j]);
				}
			}
		}
		printf("%d\n", mindistance);
	}
	return 0;
}