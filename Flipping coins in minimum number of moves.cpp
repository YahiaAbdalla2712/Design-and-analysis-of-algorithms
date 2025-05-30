//============================================================================
// Name        : Flipping coins in minimum number of moves.cpp
// Author      : Yahia
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void flip(vector<char>& coins, int l, int r){
	for(int i=0;i<=r;i++){
		coins[i] = (coins[i]=='H')?'T':'H';
	}

	cout<<"Flipped coins from index "<<l<<"to"<<r<<": ";
	for(char c:coins){
		cout<<c<<" ";
	}
	cout<<endl;
}

int minFlips(vector<char>& coins){
	int coins_no = coins.size();
	int moves = 0;

	for(int i=0;i<coins_no-1;i++){
		if(coins[i] != coins[i+1]){
			flip(coins,0,i);
			moves++;
		}
	}

	if(coins[coins_no-1] == 'T'){
		flip(coins,0,coins_no-1);
		moves++;
	}

	return moves;
}

int main() {

	vector<char> coins = {'T', 'H', 'T', 'T', 'H'};

	cout << "Initial coins: ";
	for (char c : coins) cout << c << " ";
	cout << endl;

	int result = minFlips(coins);

	cout << "All coins are heads up!\n";
	cout << "Total moves: " << result << endl;
	return 0;
}
