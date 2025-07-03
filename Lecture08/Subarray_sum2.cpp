#include<iostream>
using namespace std;


/*
	Print All the subarray sum:



*/

int main() {

	int n;
	cin >> n;
	int a[100001] {0};


	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int s = 0; s < n; s++) {

		for (int e = s; e < n; e++) {

			//Current Subarray is from : [s,e]:
			int sum = 0;

			for (int k = s; k <= e; k++) {
				sum += a[k];
			}

			cout << sum << endl;
		}

		cout << endl;

	}





}