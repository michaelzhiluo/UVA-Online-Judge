#include <iostream>
#include <bits/stdc++.h>

using namespace std;

char hashing(char x){
	switch(x){
		case 'B':
		case 'F':
		case 'P': 
		case 'V':
			return '1'; break;
		case 'C':
		case 'G':
		case 'J':
		case 'K':
		case 'Q':
		case 'S':
		case 'X':
		case 'Z':
			return '2'; break;
		case 'D':
		case 'T':
			return '3'; break;
		case 'L':
			return '4'; break;
		case 'M':
		case 'N':
			return '5'; break;
		case 'R':
			return '6'; break;
	}
	return '0';
}

int main(){
	char word[100];
	while(scanf("%s", word)==1){
		string answer = "";
		char previous = '0';
		char present;
		for(int i=0; i<strlen(word); i++){
			present = hashing(word[i]);
			if(present!='0' && present!=previous){
				answer+=present;
			}
			previous = present;
		}
		printf("%s\n", answer.c_str());
	}
    return 0;
}