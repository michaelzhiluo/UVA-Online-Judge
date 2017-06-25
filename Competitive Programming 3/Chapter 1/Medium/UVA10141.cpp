#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int numrequirements, numproposals, requirement;
    char proposal[100], answer[100];
    double price;
    for(int i=1; true; i++){
        scanf("%d %d", &numrequirements, &numproposals);
        if(numrequirements ==0){ break;}
        for(int j=0; j<numrequirements; j++){ scanf("%s");}
        double maxprice = 10000000.0;
        int maxrequirements = -1;
        for(int j=0; j<numproposals; j++){
            scanf("%s", proposal);
            scanf("%lf %d", &price, &requirement);
            for(int k=0; k<requirement; k++){ scanf("%s");}
            if(requirement > maxrequirements || (requirement == maxrequirements && price < maxprice)){
                maxrequirements = requirement;
                maxprice = price;
                memcpy(answer, proposal, strlen(proposal)+1);
            }
        }
        printf("RFP #%d\n%s\n", i, answer);
    }
}