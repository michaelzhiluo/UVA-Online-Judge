#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct coord{
	int x;
	int y;
};
coord center;

void determine(int& x, int& y){
	if(x == center.x || y == center.y){
		cout << "divisa" << endl;
	}
	else if(x > center.x){
		if(y > center.y){
			cout << "NE" << endl;
		}else{
			cout << "SE" << endl;
		}
	}else{
		if(y > center.y){
			cout << "NO" << endl;
		}else{
			cout << "SO" << endl;
		}
	}
}


int main(){
	coord temp;
	while(true){
		int TC;
		scanf("%d", &TC);
		if(TC ==0){
			break;
		}
		
		scanf("%d %d", &center.x, &center.y);
		for(int i=0; i < TC; i++){
			scanf("%d %d", &temp.x, &temp.y);
			determine(temp.x, temp.y);			
		}

	}
	return 0;
}

