#include<iostream>
using namespace std;


int main() {

	int n, t;
	cin >> n >> t;

	int a[100001] {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int s = 0;
	int tc = 0;

	for (int e = 0; e < n; e++) {
		//My Current window is : s to e (index).


		//Expand till you can or you are in the desired region.
		tc += a[e];



		//As soon as you are in an unwanted window: That means
		//you have triggered one of the below 2 conditions.
		// Try to make you window again wanted.
		/*
			When is my Window unwanted:
			1. s>e
			2. tc>t
		*/


		//I have written s<=e because I don't want my starting point
		//to overshoot ending point while shrinking the window.
		while (s <= e and tc > t) {
			//Shrinking : I am moving my start point to the index
			//where my window is desired again.

			tc -= a[s];
			s++;

		}


		//If I am standing Here that means I am at the desired window.

		//Always update maxi.

		int count = e - s + 1;
		if (maxi < count) {
			maxi = count;
		}


	}

	cout << maxi << endl;






}