#include<iostream>
using namespace std;

//Method 1:


int main() {

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}



	for (int i = 0; i < n - 1; i++) {

		if (a[i] > a[i + 1]) {

			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;

		}

	}


	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}



}