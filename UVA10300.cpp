#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		int numfarmers;
		scanf("%d", &numfarmers);
		int size, animals, env, total =0;
		for(int i=0; i<numfarmers; i++){
			scanf("%d %d %d", &size, &animals, &env);
			total+=size*env;
		}
		cout << total << endl;

	}
}

