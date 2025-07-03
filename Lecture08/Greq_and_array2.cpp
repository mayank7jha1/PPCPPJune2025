#include<iostream>
using namespace std;


int main() {

	int n, m, k;
	cin >> n >> m >> k;

	int a[100001] {0};

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int l[100001] {0}, r[100001] {0}, d[100001] {0};

	int i = 1;
	while (i <= m) {
		cin >> l[i] >> r[i] >> d[i];
		i++;
	}

	int operations_count[100001] {0};


	i = 1;
	while (i <= k) {

		int x, y;
		cin >> x >> y;

		//I will update my operations count array.
		operations_count[x] += 1;
		operations_count[y + 1] -= 1;

		i++;
	}

	//Take prefix of operation count array.
	for (int i = 1; i <= m; i++) {
		operations_count[i] = operations_count[i - 1] + operations_count[i];
	}

	// for (int i = 1; i <= m; i++) {
	// 	cout << operations_count[i] << " ";
	// }
	// cout << endl;


	//I need to perform all the operations : Operations_count times.

	//Computations: m+k+m*n:
	for (int i = 1; i <= m; i++) {

		//Currently I am at ith operation.

		//To perform ith operation:
		//l[i] index se lekar r[i] index tak d[i] * operation_count[i] ko
		//add karo.

		for (int j = l[i]; j <= r[i]; j++) {

			a[j] += (d[i] * operations_count[i]);
		}

	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;


}