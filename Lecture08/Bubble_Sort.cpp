#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	for (int i = 0; i < n - 1; i++) {

		//For My current task:
		//Put the ith largest at the end.

		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;

			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}







}




