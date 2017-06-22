#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct depreciation{
	int month =0;
	double interest = 0.0;
};


int main(){
	int nummonths;
	double downpayment;
	double loanamount;
	int numdepreciate;
	vector<depreciation> interests;
	int counter =0;
	while(true){
		interests.clear();
		counter =0;
		scanf("%d %lf %lf %d", &nummonths, &downpayment, &loanamount, &numdepreciate);
		if(nummonths <0){
			break;
		}
		double owed = loanamount;

		for(int i=0; i<numdepreciate; i++){
			depreciation temp;
			scanf("%d %lf", &temp.month, &temp.interest);
			interests.push_back(temp);
		}
		double carprice = (downpayment + loanamount)*(1.0 - interests[0].interest);
		//cout << 0 << " " << carprice << " " << owed << endl;
        if(owed < carprice){
            printf("0 months\n"); continue;
        }
		for(int i=1; i<=nummonths; i++){
			if(counter < interests.size()-1 && i >= interests[counter+1].month){
				counter++;
			}
			carprice *= (1.0 - interests[counter].interest);
			owed -= loanamount/nummonths;

			//cout << i << " " << carprice << " " << owed << endl;
			if(owed < carprice){
				printf(i <= 1 ? "1 month\n" : "%d months\n", i);
				break;
			}
		}
	}
}