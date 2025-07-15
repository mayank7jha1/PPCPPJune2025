#include<iostream>
using namespace std;


//How do we pass an array in a function.
//Arrays are always passed by reference.

int Upper_Bound(int* a, int n, int key) {

	int ans = n;
	int s = 0, e = n - 1;

	while (s <= e) {

		int mid = (s + e) / 2;
		if (a[mid] > key) {
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}

	return ans;
}



int main() {


	int n, t;
	cin >> n >> t;

	int a[100001] {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int pre[100002] {0};
	pre[0] = a[0];
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	//Idea: For every start point of the book tell
	//me from this book how many more books you can read.

	int maxi = INT_MIN;
	//Computations: n*Log2(n);
	for (int i = 0; i < n; i++) {
		/*
			Q . For this start point i how many more books you can read?
			Ans. Since we have a prefix array: The first index which will have 	value > updated total time - start point is the answer to the above question.

		*/
		int utt = t;

		if (i > 0) {
			utt += pre[i - 1];
		}


		int count = Upper_Bound(pre, n, utt) - i;

		if (count > maxi) {
			maxi = count;
		}
	}

	cout << maxi << endl;








}