#include<iostream>
using namespace std;


int main() {
	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int count = 0;

	for (int i = 0; i < n - 1; i++) {

		int flag = 0;
		count++;

		for (int j = 0; j < n - i - 1; j++) {
			count++;
			if (a[j] > a[j + 1]) {
				count++;
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 1;
			}
		}


		if (flag == 0) {
			break;
		}

	}


	cout << count << endl;

	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }







}




