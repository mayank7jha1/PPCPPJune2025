#include<iostream>
using namespace std;



/*

	Given an array you need to find a
	triplet(x,y,z) whose sum is target.

	Dublicate pairs are allowed.

	6 9
	1 2 7 3 6 2



*/

int main() {

	int n, target;
	cin >> n >> target;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	for (int i = 0; i < n - 2; i++) {
		int first = a[i];
		for (int j = i + 1; j < n - 1; j++) {
			int second = a[j];
			for (int k = j + 1; k < n; k++) {
				int third = a[k];

				if (first + second + third == target) {
					cout << first << " " << second << " " << third << endl;
				}

			}

		}


	}









}





