#include<iostream>
using namespace std;


int main() {


	int n, t;
	cin >> n >> t;

	int a[100001] {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int maxi = INT_MIN;

	//Computations: n*n
	for (int i = 0; i < n; i++) {
		int csi = i;

		int count = 0;
		int tc = 0;

		for (int cei = csi; cei < n; cei++) {

			tc += a[cei];
			if (tc > t) {
				break;
			}

			count++;
		}

		if (count > maxi) {
			maxi = count;
		}
	}


	cout << maxi << endl;





}