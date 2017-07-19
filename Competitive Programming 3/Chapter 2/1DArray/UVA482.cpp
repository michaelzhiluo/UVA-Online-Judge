#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main(){
	int TC, l;
	scanf("%d\n", &TC);
	char placeholder[100000];
	while(TC--){
		scanf("\n");
		fgets(placeholder, 100000, stdin);
		vector<int> indexes;
		for(char* temp = strtok(placeholder, " \n"); temp; temp = strtok(NULL, " \n")){
			sscanf(temp, "%d", &l);
			indexes.push_back(l);
		}
		fgets(placeholder, 100000, stdin);
		string numbers[indexes.size()];
		l=0;
		for(char* temp = strtok(placeholder, " \n"); temp; temp = strtok(NULL, " \n")){
			numbers[indexes[l]-1] = temp;
			l++;
		}
		for(int i=0; i<indexes.size(); i++){
			printf("%s\n", numbers[i].c_str());
		}

		if(TC!=0){
			printf("\n");
		}
	}
    return 0;
}