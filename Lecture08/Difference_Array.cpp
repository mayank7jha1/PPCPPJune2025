#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int difference[100001] {0};

	int q;
	cin >> q;
	int i = 1;


	//Resolution of your range.
	//Resolving your range.
	while (i <= q) {

		int l, r, value;
		cin >> l >> r >> value;


		//You need to build prefix/difference
		//array according to every query.
		difference[l] += value;
		difference[r + 1] -= value;

		i++;
	}


	//After doing task for every query now take
	//prefix sum.

	// difference[0] = difference[0];

	//I am goinf till n-1 only why because the value
	//stored in n index is not required.

	for (int i = 1; i < n; i++) {
		difference[i] = difference[i - 1] + difference[i];
	}

	//Add difference array in original array.

	for (int i = 0; i < n; i++) {
		a[i] = a[i] + difference[i];
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}


}




