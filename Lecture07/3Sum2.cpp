#include<iostream>
using namespace std;


int main() {

	int t;
	cin >> t;

	int i = 1;

	while (i <= t) {

		int n;
		cin >> n;
		// int a[n];
		// for (int i = 0; i < n; i++) {
		// 	cin >> a[i];
		// 	a[i] %= 10;
		//}

		// int b[n] {0};

		// for (int i = 0; i < n; i++) {
		// 	// b[i] = a[i] % 10;
		// 	// a[i] = a[i] % 10;
		// 	a[i] %= 10;
		// }

		// int freq[10] {0};

		// //We iterate over the original array.
		// for (int i = 0; i < n; i++) {
		// 	int element = a[i];
		// 	freq[element]++;
		// }

		int freq[10] {0};

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x %= 10;
			freq[x]++;
		}

		//Now shortend the freq array.
		//I will iterate over the freq array.
		for (int i = 0; i <= 10; i++) {
			if (freq[i] > 3) {
				freq[i] = 3;
			}
		}

		//We need to create the shortend array.

		/*

			freq array: size 10:

			index:      value
			2      ----> 3
			5      ----> 2
			7      ----> 3

			shortend array : b[31]
			2,2,2,5,5,7,7,7



			i = element i.e. ye vo vcheez hain jisko aapko new
			array me jalna hain kitni bar freq[i] bar.


		*/

		int b[31] {0};
		int k = 0;//This is the index in b array.
		//This tells me how many elements are
		//currently inside b array.


		for (int i = 0; i < 10; i++) {
			//Mera current index is i and ye vo
			//element hai jisse mujhe new array
			//me freq[i] times daalna hain.
			int j = 1;
			while (j <= freq[i]) {

				b[k] = i;
				k++;

				j++;
			}

			// while (freq[i]--) {
			// 	b[k] = i;
			// 	k++;
			// }

		}

		int flag = 0;

		for (int i = 0; i < k - 2; i++) {
			int first = b[i];
			for (int j = i + 1; j < k - 1; j++) {
				int second = b[j];
				for (int z = j + 1; z < k; z++) {
					int third = b[z];

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