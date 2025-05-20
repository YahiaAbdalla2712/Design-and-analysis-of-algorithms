//============================================================================
// Name        : Recursive counting using merge sort.cpp
// Author      : Yahia
// Version     :
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int left,int mid,int right){
	int n1=mid-left+1;
	int n2=right-mid;

	vector<int> L(n1),R(n2);

	for(int i=0;i<n1;i++){
		L[i] = arr[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i] = arr[mid+1+i];
	}

	int i=0,j=0,k=left;
	while(i<n1 && j<n2){
		if(L[i] <= R[j]){
			arr[k++] = L[i++];
		}
		else{
			arr[k++] = R[j++];
		}
	}

	while(i<n1){
		arr[k++]=L[i++];
	}

	while(j<n2){
		arr[k++]=R[j++];
	}

}

void mergeSort(vector<int>& arr,int left,int right){
	if(left<right){
		int mid = (left+right)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}

int count_occurrences(vector<char>& arr,int left,int right,char x){
	if(left>right){
		return 0;
	}
	if(left == right){
		if(arr[left] == x){
			return 1;
		}
		else{
			return 0;
		}
	}
	int mid = (left+right)/2;
	int left_count = count_occurrences(arr,left,mid,x);
	int right_count = count_occurrences(arr,mid+1,right,x);
	return left_count + right_count;
}

int main() {

	vector<int> arr={2,3,7,4,0,9,-1,10,88,25};
	vector<char> chars = {'A','s','v','g','r','A','A','k','l','s','A'};
	int n = arr.size();
	mergeSort(arr,0,n-1);
	cout<<"sorted array: ";
	for(int x:arr){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<"Minimum= "<<arr[0]<<endl;
	cout<<"Maximum= "<<arr[n-1]<<endl;
	int m = chars.size();
	int number_of_occ_of_A = count_occurrences(chars,0,m-1,'A');
	cout<<"number of occurrences of letter A = "<<number_of_occ_of_A<<endl;

	return 0;
}
