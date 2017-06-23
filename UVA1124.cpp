#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main() {
	//ofstream fout ("output.txt");
    //ifstream fin ("input.txt");
    string temp;
    while(getline(cin, temp)){
    	cout << temp << endl;
    }
    return 0;
}