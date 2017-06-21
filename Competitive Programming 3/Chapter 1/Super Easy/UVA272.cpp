#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main() {
	//ofstream fout ("output.txt");
    //ifstream fin ("input.txt");
    vector<string> quotes;
    string temp;
    bool inquotes = false;
    while(getline(cin, temp)){
    	quotes.push_back(temp);
    }
    for(int i=0; i<quotes.size(); i++){
    	for(int j=0; j<quotes[i].size(); j++){
    		if(quotes[i][j] == '"'){
    			quotes[i].erase(j, 1);
    			if(inquotes){
    				quotes[i].insert(j, "''");
    			}else{
    				quotes[i].insert(j, "``");
    			}
    			inquotes = !inquotes;
    		}
    	}
    }
    for(int i=0; i<quotes.size(); i++){
    	cout << quotes[i] << endl;
    }
    return 0;
}