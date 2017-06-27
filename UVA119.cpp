#include <stdio.h>
#include <string.h>
#include <vector>
#define MAXPEOPLE 10
#define NAMELEN	32

using namespace std;
typedef struct Person Person;
struct Person {
    char name[NAMELEN];
    int total =0;
};

vector<Person> people;
int npeople;

void
addperson(char *name)
{
    
    Person temp;
	strcpy(temp.name, name);
    people.push_back(temp);
    npeople++;
}

Person* lookup(char *name)
{
    int i;

    for(i=0; i<npeople; i++){
        if(strcmp(name, people[i].name) == 0){
            return &people[i];
        }
    }
}

int main()
{
    char name[NAMELEN];
    int i, j, np, amt, ng;
    Person *giver, *receiver;
    int counter =0;
    while(scanf("%d", &np) != EOF){
        if(counter){
            printf("\n");
        }
        people.clear();

        for(i=0; i<np; i++) {
            scanf("%s", name);
            addperson(name);
        }

        for(i=0; i<np; i++) {
            scanf("%s %d %d", name, &amt, &ng);
            giver = lookup(name);

            for(j=0; j<ng; j++) {
                scanf("%s", name);
                receiver = lookup(name);
                giver->total -= amt/ng;
                receiver->total += amt/ng;
            }
        }

        for(i=0; i<np; i++){
            printf("%s %d\n", people[i].name, people[i].total);
        }
        counter++;
    }
    return 0;
}

