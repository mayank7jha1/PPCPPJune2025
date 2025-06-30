#include<iostream>
using namespace std;


/*
	Input Format:
	3 4 5 6 17 18 19 10 1 18



*/

int main() {

	int a[1001];

	int x;
	int index = 0;
	while (cin >> x) {
		a[index] = x;
		index++;
	}

	for (int i = 0; i < index; i++) {
		cout << a[i] << " ";
	}
}


