#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC, stations;
	int sum, index;
	scanf("%d", &TC);
	bool works;
	for(int c = 1; c<=TC; c++){
		sum =0;
		works = false;
		scanf("%d", &stations);
		int gains[stations];
		int costs[stations];
		for(int i=0; i<stations; i++){
			scanf("%d", &gains[i]);
		}
		for(int i=0; i<stations; i++){
			scanf("%d", &costs[i]);
		}

	}
    return 0;
}