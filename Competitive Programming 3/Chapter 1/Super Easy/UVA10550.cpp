#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int clockwise(int& start, int& end){
	if(start >= end){
		return 9*(start - end);
	}
	return 9*(start - end + 40);
}

int counterclockwise(int& start, int& end){
	if(start <= end){
		return 9*(end - start);
	}
	return 9*(end - start + 40);
}

int main(){
	//FILE* in = fopen("input.txt", "r");
	//FILE * out = fopen("output.txt", "r");
	int a,b,c,d;
	int totalangle = 360*3;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF){
		if(a ==0 && b==0 && c==0 && d==0){
			break;
		}
		cout << totalangle + clockwise(a, b) + counterclockwise(b, c) + clockwise(c, d) << endl;

	}
	
	return 0;
}