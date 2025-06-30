#include<iostream>
using namespace std;


int main() {

	int t;
	cin >> t;

	int i = 1;

	while (i <= t) {

		//Logic for Program.
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int flag = 0;

		// 0-n-2 : n-2*n-1*n ~~ (n^3):
		// (2*10^5)^3: 8*10^15*1000:
		// ~10^18*8

		// 1 sec: 10^8

		for (int i = 0; i < n - 2; i++) {
			int first = a[i];

			for (int j = i + 1; j < n - 1; j++) {
				int second = a[j];

				for (int k = j + 1; k < n; k++) {
					int third = a[k];

					if ((first + second + third) % 10 == 3) {
						cout << "YES" << endl;
						flag = 1;
						break;
					}

				}

				if (flag == 1) {
					break;
				}
			}

			if (flag == 1) {
				break;
			}
		}


		if (flag == 0) {
			cout << "NO" << endl;
		}


		i++;
	}










}