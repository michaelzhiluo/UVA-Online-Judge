#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int length;
	map<string, map<string, string> > change;
	change["+x"]["+y"] = "+y";
	change["+x"]["-y"] = "-y";
	change["+x"]["+z"] = "+z";
	change["+x"]["-z"] = "-z";
	change["-x"]["+y"] = "-y";
	change["-x"]["-y"] = "+y";
	change["-x"]["+z"] = "-z";
	change["-x"]["-z"] = "+z";
	change["+y"]["+y"] = "-x";
	change["+y"]["-y"] = "+x";
	change["+y"]["+z"] = "+y";
	change["+y"]["-z"] = "+y";
	change["-y"]["+y"] = "+x";
	change["-y"]["-y"] = "-x";
	change["-y"]["+z"] = "-y";
	change["-y"]["-z"] = "-y";
	change["+z"]["+y"] = "+z";
	change["+z"]["-y"] = "+z";
	change["+z"]["+z"] = "-x";
	change["+z"]["-z"] = "+x";
	change["-z"]["+y"] = "-z";
	change["-z"]["-y"] = "-z";
	change["-z"]["+z"] = "+x";
	change["-z"]["-z"] = "-x";

	while(true){
		scanf("%d", &length);
		if(length ==0){
			break;
		}
		string final, initial;
		initial = "+x";
		for(long i = 0; i < length-1; i++) {
			cin >> final;
			if(final != "No")
				initial = change[initial][final];
		}
		printf("%s\n", initial.c_str());
	}
}