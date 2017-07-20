#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int numcards, index, length;
	string card, word;
	while(scanf("%d", &numcards)==1 && numcards){
		vector<string> sequence(numcards);
		index =0;
		for(int i=0; i<numcards; i++){
			cin >> card >> word;
			length = word.length();
			while(length){
				if(sequence[index] == ""){
					length--;
				}
				index = (index+1)%numcards;
			}
			sequence[(index-1+numcards)%numcards] = card;
		}
		for(int i=0; i<numcards; i++){
			if(i){
				printf(" ");
			}
			printf("%s", sequence[i].c_str());
		}
		printf("\n");
	}
    return 0;
}