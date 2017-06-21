#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	char c[100];
	int counter =1;
	while(true){
		scanf("%s", &c);
		if(strcmp(c, "*")==0){
			break;
		}
		printf("Case %d: ", counter++);
		if(strcmp(c, "Hajj")==0){
			printf("Hajj-e-Akbar\n");
		}else if(strcmp(c, "Umrah")==0){
			printf("Hajj-e-Asghar\n");
		}
	}
}

