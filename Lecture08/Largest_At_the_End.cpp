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

	int maxi = 0;//I will want to initialise it with a value the starting point.

	for (int i = 0; i < n; i++) {

		if (a[maxi] < a[i]) {
			maxi = i;
		}

	}


	int temp = a[maxi];
	a[maxi] = a[n - 1];
	a[n - 1] = temp;


	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}



}