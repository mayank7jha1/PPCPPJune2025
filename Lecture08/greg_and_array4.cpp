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

	//10^15: Computations:

	i = 1;
	while (i <= k) {

		int x, y;
		cin >> x >> y;

		for (int z = x; z <= y; z++) {

			for (int o = l[z]; o <= r[z]; o++) {
				//For current Operation: l[z],r[z],d[z]
				a[o] += d[z];
			}
		}

		i++;
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}

}




