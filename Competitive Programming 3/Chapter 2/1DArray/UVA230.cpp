#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Book{
    string title, author;
}

int main(){
    string input = "\"The Canterbury Tales\" by Chaucer, G.";
    char a[200], t[200];
    sscanf(input.c_str(), "\"%[^\"]\" by %[^\n\r]", t, a);
    printf("%s\n", a);
    printf("%s\n", t);    
    
    return 0;
}