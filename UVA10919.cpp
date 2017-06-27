#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(){
	int courses, categories, placeholder, r, c;
	unordered_set< int > hash;
	unordered_set< int >::const_iterator iter;
	while(scanf("%d %d", &courses, &categories)==2){
		hash.clear();
		while(courses--){
			scanf("%d", &placeholder);
			hash.insert(placeholder);
		}
		bool met = true;
		while(categories--){
			scanf("%d %d", &r, &c);
			while(r--){
				scanf("%d", &placeholder);
				iter = hash.find(placeholder);
				if(iter != hash.end()){
					c--;
				}
			}
			if(c>0){
				met = false;
			}
		}
		printf(met ? "yes\n" : "no\n");
	}
	return 0;
}