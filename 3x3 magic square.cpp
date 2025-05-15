//============================================================================
// Name        : Lab1.cpp
// Author      : Yahia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool check_sum(vector<vector<int>>& arr){
	int sum = 0;
	sum = arr[0][0]+arr[0][1]+arr[0][2];
	for(int i=0;i<3;i++){
		if(arr[i][0]+arr[i][1]+arr[i][2] != sum)return false;
	}

	for(int i=0;i<3;i++){
		if(arr[0][i]+arr[1][i]+arr[2][i] != sum)return false;
	}

	if(arr[0][0]+arr[1][1]+arr[2][2] != sum)return false;
	if(arr[0][2]+arr[1][1]+arr[2][0] != sum)return false;

	return true;

}




int main() {

	vector<int> num_arr={1,2,3,4,5,6,7,8,9};
	vector<vector<vector<int>>> valid_permutations;
	int number_of_valid_permutations = 0;

	do{
		vector<vector<int>> threexthree(3, vector<int>(3));
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				threexthree[i][j] = num_arr[i*3+j];
			}
		}
		if(check_sum(threexthree)){
			valid_permutations.push_back(threexthree);
			number_of_valid_permutations++;
		}
	}while(next_permutation(num_arr.begin(),num_arr.end()));

	for (const auto& perm : valid_permutations) {
	    for (const auto& row : perm) {
	        for (int num : row) {
	            cout << num << " ";
	        }
	        cout << endl;
	    }
	    cout << "------------------------" << endl;
	}


	return 0;
}
