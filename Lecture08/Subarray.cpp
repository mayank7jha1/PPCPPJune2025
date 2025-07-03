#include<iostream>
using namespace std;


int main() {

	int n;
	cin >> n;
	int a[100001] {0};


	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	for (int s = 0; s < n; s++) {

		for (int e = s; e < n; e++) {

			//Currently We are talking about a
			//subarray with starting point as
			//s and ending point as e index.

			//This is for printing the current subarray.

			for (int k = s; k <= e; k++) {
				cout << a[k] << " ";
			}

			cout << endl;
		}

		cout << endl;



	}










}