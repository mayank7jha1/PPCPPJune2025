#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	//Computation: n*n
	//Sorted Array: n
	for (int i = 1; i < n; i++) {
		//Current Unsorted Element
		int use = a[i];

		//Specify the ranges of sorted half.
		int j = i - 1;


		while ((j >= 0) and a[j] > use) {
			//Shifting:
			a[j + 1] = a[j];
			j--;
		}

		//Now put the cue at its correct position.
		a[j + 1] = use;
	}


	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}







}