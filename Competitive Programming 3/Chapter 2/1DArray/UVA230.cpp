#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Book{
    char title[1000], author[1000]; 
    bool operator < (Book& a){
        if(strcmp(title, a.title) !=0){
            return strcmp(title, a.title) <0;
        }
        return strcmp(author, a.author) < 0;
    }
};

struct charcmp{
    bool operator()(char *a, char* b){
        return strcmp(a,b)<0;
    }
} temp;


int main(){
    char input[2000], a[1000], t[1000];
    vector<Book> books;
	vector<char*> returned;
    map<char*, bool, charcmp> exists;
    while(true){
        fgets (input, 2000, stdin);
        if(strcmp(input, "END\n")==0){
            break;
        }
        string input1 = string(input);
        sscanf(input1.c_str(), "\"%[^\"]\" by %[^\n\r]", t, a);
        Book temp;
        strcpy(temp.title, t);
        strcpy(temp.author, a);
        books.push_back(temp);
    }
    sort(books.begin(), books.end());

    for(vector<Book>::iterator i = books.begin(); i!=books.end(); i++){
        exists.insert(pair<char*, int>(i->title, true));
    }

    while(true){
        fgets(input, 2000, stdin);
        if(strcmp(input, "END\n") ==0){
            break;
        }
        string input1 = string(input);
        sscanf(input1.c_str(), "%s \"%[^\"]\"", t, a);
        if(!strcmp(t, "BORROW")){
            exists[a] = false;
        }else if(!strcmp(t, "RETURN")){
            exists[a] = true;
			char temp[1000];
			strcpy(temp, a);
			returned.push_back(temp);
        }else if(!strcmp(t, "SHELVE")){
			sort(returned.begin(), returned.end(), temp);
			for (int i = 0; i < returned.size(); i++) {
				printf("%s\n", returned[i]);
			}
			printf("END\n");
        }

    }
    for(map<char*,bool>::iterator it=exists.begin(); it!=exists.end(); it++){
        cout << it->first << " => " << it->second << endl;
    }
    return 0;
}