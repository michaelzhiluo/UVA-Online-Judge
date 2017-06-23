#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// Scanf 2 hard 5 me like you have to reach % and & which is pain
int main(){
	int TC;
	cin >> TC;
	int placeholder;
	while(TC--){
		int numcommands;
		cin >> numcommands;
		int commands[numcommands];
		for(int i=0; i<numcommands; i++){
			string temp;
			cin >> temp;
			if(temp == "LEFT"){
				commands[i] = -1;
			}else if(temp == "RIGHT"){
				commands[i] = 1;
			}else{
				cin >> temp >> placeholder;
				commands[i]= commands[placeholder-1];
			}
		}
		int sum =0;
		for(int i=0; i<numcommands; i++){
			sum+=commands[i];
		}
		cout << sum << endl;



	}

}