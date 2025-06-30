#include<iostream>
using namespace std;



/*

	Given an array you need to find a
	pair(x,y) whose sum is target.

	Dublicate pairs are allowed.

	6 9
	1 2 7 3 6 2

	2,7
	3,6
	7,2



*/

int main() {

	int n, target;
	cin >> n >> target;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// for (int i = 0; i < n; i++) {
	// 	//I am Currently working for Pair(a[i],?)
	// 	int first = a[i];

	// 	//I will search for the second element in the
	// 	//entire array skipping the first element index.

	// 	for (int j = 0; j < n; j++) {

	// 		//Treat the current element here as the second
	// 		int second = a[j];

	// 		if (j == i) {
	// 			continue;
	// 		}

	// 		if (first + second == target) {
	// 			//We have found a pair.
	// 			cout << first << " " << second << endl;
	// 		}


	// 	}
	// }



	for (int i = 0; i < n - 1; i++) {
		//I will treat elements from [0,n-2] as the first element of the pair.
		//I am Currently working for Pair(a[i],?)
		int first = a[i];

		//I will search for the second element from i+1
		// to the last element of the array..

		for (int j = i + 1; j < n; j++) {

			//Treat the current element here as the second
			int second = a[j];

			if (first + second == target) {
				//We have found a pair.
				cout << first << " " << second << endl;
			}
		}
	}




	// int x = 100;

	// if (x > 10) {

	// }else if (x > 97) {

	// }









}





