#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int numdevices, numoperations, maxcapacity, placeholder;
    for(int j =1; true; j++){
        bool fuse = false;
        scanf("%d %d %d", &numdevices, &numoperations, &maxcapacity);
        if(numdevices ==0 && numoperations ==0 && maxcapacity ==0){
            break;
        }
        int capacity[numdevices];
        bool power[numdevices];
        for(int i=0; i<numdevices; i++){
            scanf("%d", &capacity[i]);
            power[i] = false;
        }
        int totalcapacity =0;
        int maxpower =0;
        for(int i=0; i<numoperations; i++){
            scanf("%d", &placeholder);
            //cout << power[placeholder-1]<< endl;
            if(power[placeholder-1]){
                totalcapacity -= capacity[placeholder-1];
            }else{
                totalcapacity += capacity[placeholder-1];
            }
            power[placeholder-1] = !power[placeholder-1];
            if(totalcapacity > maxcapacity){
                fuse = true;
            }
            if(totalcapacity > maxpower){
                maxpower = totalcapacity;
            }
        }
        printf("Sequence %d\n", j);
        if(fuse){
            printf("Fuse was blown.\n\n");
        }else{
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n", maxpower);
        }

    }



    return 0;
}