//============================================================================
// Name        : Lab2.cpp
// Author      : Yahia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;




int main() {
	vector<int> denominations = {1000,500,100,50,20,10,5,2,1};
	vector<int> currency_used;
	int changed_value;
	cout<<"Enter amount to change:";
	cin>>changed_value;

	for(int i=0;i<denominations.size();i++){
		while(changed_value>=denominations[i]){
			changed_value -= denominations[i];
			currency_used.push_back(denominations[i]);
		}
	}

	cout<<"the minimum number of coins needed to make the change: "<<currency_used.size()<<endl;
	cout<<"All denominations used";
	for(int i=0;i<currency_used.size();i++){
		cout<<currency_used[i]<<" ";
	}


	return 0;
}
