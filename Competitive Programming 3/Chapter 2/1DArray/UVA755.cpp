#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string convertToString(char* c){
	string answer = "";
	for(int i=0; i<strlen(c); i++){
		int x = (int)c[i];
		if(x >= 48 && x<=57){
			answer+=c[i];
		}else if(x>=65 && x<= 67){
			answer+='2';
		}else if(x>=68 && x<= 70){
			answer+='3';
		}else if(x>=71 && x<= 73){
			answer+='4';
		}else if(x>=74 && x<= 76){
			answer+='5';
		}else if(x>=77 && x<= 79){
			answer+='6';
		}else if(x>=80 && x<= 83 && x!=81){
			answer+='7';
		}else if(x>=84 && x<= 86){
			answer+='8';
		}else if(x>=87 && x<= 89){
			answer+='9';
		}
	}
	return answer.substr(0, 3) + "-" + answer.substr(3);
}

bool pairCompare(pair<string, int>& firstElem, pair<string, int>& secondElem){
  return firstElem.first < secondElem.first;
}

int main(){
	int TC, length;
	char c[1000];
	scanf("%d", &TC);
	map<string, int> phonenumber;
	vector< pair<string, int> > answer;
	loop:
	while(TC--){
		answer.clear();
		phonenumber.clear();
		scanf("%d\n", &length);
		while(length--){
			fgets(c, 1000, stdin);
			string temp = convertToString(c);
			if(phonenumber.find(temp) == phonenumber.end()){
				phonenumber[temp] = 1;
			}else{
				phonenumber[temp]++;
			}
		}
		for(map<string, int>::iterator i = phonenumber.begin(); i!= phonenumber.end(); i++){
			if(i->second>1){
				answer.push_back(make_pair(i->first, i->second));
			}
		}
		sort(answer.begin(), answer.end(), pairCompare);
		for(int i=0; i<answer.size(); i++){
			printf("%s %d\n", answer[i].first.c_str(), answer[i].second);
		}
		if(answer.size() ==0){
			printf("No duplicates.\n");
		}
		if(TC){
			printf("\n");
		}
	}
    return 0;
}