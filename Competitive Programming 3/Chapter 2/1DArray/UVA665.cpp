#include <iostream>
#include <bits/stdc++.h>

// Heads up, troll question, you cannot determine UNIQUE counterfeit coint with >, < so only focus on =
using namespace std;
int main(){
	int TC, n, k, p;
	char comparator;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &n, &k);
		bool notcounterfeit[n+1];
		for(int i=0; i<n+1; i++){
			notcounterfeit[i] = false;
		}
		for(int x=0; x<k; x++){
			scanf("%d", &p);
			int left[p], right[p];
			for(int i=0; i<p; i++){
				scanf("%d", &left[i]);
			}
			for(int i=0; i<p; i++){
				scanf("%d", &right[i]);
			}
			scanf(" %c", &comparator);
			if(comparator == '='){
				for(int i=0; i<p; i++){
					notcounterfeit[left[i]] = true;
					notcounterfeit[right[i]] = true;
				}
			}
		}
		int counter =0;
		for(int i=1; i<=n; i++){
			if(!notcounterfeit[i]){ counter++; p =i;}
		}
		printf(counter!=1 ? "0\n" : "%d\n", p);
		if(TC){ printf("\n");}
	}
}