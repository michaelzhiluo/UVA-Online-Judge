#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Book{
    string title, author; 
    bool operator < (Book& a){
        if(author != a.author){
            return author < a.author;
        }
        return title < a.title;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    char a[1000], t[1000];
    string input;
    vector<Book> books;
	vector<Book> returned;
    map<string, bool> exists;
    while(getline(cin, input)){
        if(input == "END"){
            break;
        }
        sscanf(input.c_str(), "\"%[^\"]\" by %[^\n\r]", t, a);
        Book temp;
        temp.title = string(t);
        temp.author = string(a);
        books.push_back(temp);
    }

    sort(books.begin(), books.end());

    for(vector<Book>::iterator i = books.begin(); i!=books.end(); i++){
        exists[i->title] = true;
    }

    while(getline(cin, input)){
        if(input == "END"){
            break;
        }
        if(input[0] == 'B'){
            sscanf(input.c_str(), "BORROW \"%[^\"]\"", a);
            exists[string(a)] = false;
        }else if(input[0] == 'R'){
            sscanf(input.c_str(), "RETURN \"%[^\"]\"", a);
            string temp = string(a);
            for(int i=0; i<books.size(); i++){
                if(books[i].title == temp){
                    returned.push_back(books[i]);
                    break;
                }
            }
        }else if(input == "SHELVE"){
			sort(returned.begin(), returned.end());
            if(returned.size()!=0){
                int counter =0;
                foo:
                for(int i=0; i<books.size(); i++){
                    if(books[i].title == returned[counter].title){
                        counter++;
                        exists[books[i].title] = true;
                        for(int j=i-1; j>=0; j--){
                            if(exists[books[j].title]){
                                printf("Put \"%s\" after \"%s\"\n", returned[counter-1].title.c_str(), books[j].title.c_str());
                                goto foo;
                            }
                        }
                        printf("Put \"%s\" first\n", returned[counter-1].title.c_str());
                    }
                }
            }
            printf("END\n");
            returned.clear();
        }
    }
    return 0;
}