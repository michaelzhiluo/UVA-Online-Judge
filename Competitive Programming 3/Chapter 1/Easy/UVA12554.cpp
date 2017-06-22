#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int numpeople;
	scanf("%d", &numpeople);
	char people[numpeople][200];
	char birthdaylyrics[][20] = {
        "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"
    };
	for(int i=0; i<numpeople; i++){
		scanf("%s", &people[i]);
	}
	int numtimes = 16*(int)ceil(numpeople/16.0);
	for(int i=0; i<numtimes; i++){
		printf("%s: %s\n", people[i%numpeople], birthdaylyrics[i%16]);
	}
}