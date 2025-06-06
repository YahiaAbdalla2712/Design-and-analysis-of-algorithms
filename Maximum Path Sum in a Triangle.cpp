//============================================================================
// Name        : Maximum Path Sum in a Triangle.cpp
// Author      : Yahia
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void get_max_sum_dp(vector<vector<int>>& s){
	int size = s.size();

	for(int i = size-2;i>=0;i--){
		for(int j = 0; j < size;j++){
			s[i][j] += max(s[i+1][j], s[i+1][j+1]);
		}
	}

}




int main() {
	vector<vector<int>> data =
	{{2},
	 {5,4},
	 {3,4,7},
	 {1,6,9,6}
	};

	get_max_sum_dp(data);
	cout<<"the maximum sum = "<<data[0][0]<<endl;
	return 0;
}
