#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int days = 1;

bool checkexceeds(double& distance, double& h){
    if(distance <0){
        printf("failure on day %d\n", days);
        return true;
    }
    else if(distance > h){
        printf("success on day %d\n", days);
        return true;
    }
    return false;
}

int main(){
    double h, u , d, f;
    while(true){
        double distance =0;
        days = 1;
        scanf("%lf %lf %lf %lf", &h, &u, &d, &f);
        if(h <=0){
            break;
        }
        f = u*f/100.0;
        //cout << f << endl;
        for(days;true; days++){
            distance += u;
            if (checkexceeds(distance, h)){
                break;
            }
            distance -= d;
            if(checkexceeds(distance, h)){
                break;
            }
            u = fmax(u-f, 0);
        }
    }

    return 0;
}