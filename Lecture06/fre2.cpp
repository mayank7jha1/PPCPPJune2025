#include<iostream>
using namespace std;


/*
	Given an array of positive integers find the frequency of each element in the
	array.


	6
	1 3 3 3 3 6

	1->1
	3->4
	6->1


*/

int main() {


	// int n, target;
	// cin >> n >> target;
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//n*n:
	// for (int i = 0; i < n; i++) {

	// 	if (a[i] > 0) {
	// 		int target = a[i];
	// 		int count = 0;

	// 		for (int j = 0; j < n; j++) {

	// 			if (a[j] == target) {
	// 				a[j] = -1;
	// 				count++;
	// 			}

	// 		}

	// 		cout << target << "-->" << count << endl;
	// 	}

	// }


	int freq[100] {0};

	//I will go to every element of the array.
	for (int i = 0; i < n; i++) {
		int element = a[i];

		freq[element]++;
	}


	for (int i = 0; i < 100; i++) {

		if (freq[i] > 0) {

			cout << i << "--->" << freq[i] << endl;

		}

	}













	




}






