#include<iostream>
using namespace std;


//Sublime: 2mb:
//1 array bana sakte : 10^8
//2 array 10^7 X 2


int main() {

	int n, m, k;
	cin >> n >> m >> k;

	int a[100003] {0};

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int l[100003] {0}, r[100003] {0}, d[100003] {0};

	int i = 1;
	while (i <= m) {
		cin >> l[i] >> r[i] >> d[i];
		i++;
	}

	int operations_count[100003] {0};


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

	//I need to perform all the operations : Operations_count times.
	int difference[100003] {0};

	//Build your difference:
	// for this go to every index of operations and do the task:
	for (int i = 1; i <= m; i++) {

		int x = l[i];
		int y = r[i];

		difference[x] += (d[i] * operations_count[i]);
		difference[y + 1] -= (d[i] * operations_count[i]);
	}

	//Take prefix of your difference array.
	for (int i = 1; i <= n; i++) {
		difference[i] = difference[i - 1] + difference[i];
	}

	for (int i = 1; i <= n; i++) {
		a[i] = a[i] + difference[i];
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}


	cout << endl;

}