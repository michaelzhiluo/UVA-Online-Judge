#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct {
	long int width;
	long int length;
} Rectangle;


int main(){
	//FILE *in = fopen("input.txt", "r");
	//FILE *out = fopen("output.txt", "w");

	int TC;
	scanf("%d", &TC);
	
	Rectangle rect;
	while(TC--){
		scanf("%d %d", &rect.width, &rect.length);
		long int answer = (int)ceil((rect.width - 2)/3.0)*ceil((rect.length - 2)/3.0);
		cout << answer << endl;
	}
	return 0;
}