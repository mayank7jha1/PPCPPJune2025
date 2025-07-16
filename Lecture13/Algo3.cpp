#include<iostream>
#include<algorithm>
using namespace std;


int main() {


	int a[] {2, 3, 4, 5, 5, 5, 5, 5, 5, 6, 7, 8};
	int n = sizeof(a) / sizeof(int);
	cout << n << endl;

	//log2(n)
	cout << binary_search(a, a + n, 5) << endl;
	cout << lower_bound(a, a + n, 5) - a << endl;
	cout << upper_bound(a, a + n, 5) - a << endl;
	cout << upper_bound(a, a + n, 5) - lower_bound(a, a + n, 5) << endl;
	cout << lower_bound(a, a + n, 19) - a << endl;

	// 8010 8014 8018 8022 8026 - - - -
	// 8022 - 8010 = 12 byte /4 =3











}