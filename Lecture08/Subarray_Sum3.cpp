#include<iostream>
using namespace std;

/*
	Given an array check if it contains a subarray
	whose sum is zero.

*/


int main() {

	int n;
	cin >> n;
	int a[100001] {0};


	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int flag = 0;

	for (int s = 0; s < n; s++) {

		for (int e = s; e < n; e++) {


			int sum = 0;

			for (int k = s; k <= e; k++) {
				sum += a[k];
			}



			if (sum == 0) {
				cout << "YES" << endl;
				flag = 1;
				break;
			}


		}



		if (flag == 1) {
			break;
		}

	}

	if (flag == 0) {
		cout << "NO" << endl;
	}


}







