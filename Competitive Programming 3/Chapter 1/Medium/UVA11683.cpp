#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> capacity;

int calculatelaser(int& height){
	bool on = false;
	int numcuts =0;
	for(int i=0; i<capacity.size(); i++){
		if(height > capacity[i] && !on){
			on = true;
		}else if(on && capacity[i] >= height ){
			on = false; 
			numcuts++;
		}
	}
	if(height > capacity[capacity.size()-1]){
		numcuts++;
	}
	return numcuts;
}

int main(){
	int height, width, placeholder;
	while(true){
		scanf("%d", &height);
		if(height ==0){ break;}
		scanf("%d", &width);
		capacity.clear();
		for(int i=0; i<width; i++){
			scanf("%d", &placeholder);
			capacity.push_back(placeholder);
		}
		int total =0;
		for(int i=height; i>=1; i--){
			total += calculatelaser(i);
		}
		printf("%d\n", total);
	}
	return 0;
}