#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
	int TC, l;
	scanf("%d\n", &TC);
	char placeholder[100000];
	while(TC--){
		fgets(placeholder, 100000, stdin);
		fgets(placeholder, 100000, stdin);
		vector<int> indexes;
		for(char* temp = strtok(placeholder, " \n"); temp; temp = strtok(NULL, " \n")){
			sscanf(temp, "%d", &l);
			indexes.push_back(l);
		}
		fgets(placeholder, 100000, stdin);
		char* numbers[indexes.size()];
		l=0;
		for(char* temp = strtok(placeholder, " \n"); temp; temp = strtok(NULL, " \n")){
			strcpy(numbers[indexes[l]-1], temp);
			printf("%s\n", numbers[indexes[l]-1]);
			l++;
		}
		printf("\n");
	}
    return 0;
}