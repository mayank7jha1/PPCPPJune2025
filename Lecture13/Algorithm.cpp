#include<iostream>
#include<algorithm>
using namespace std;


int main() {


	int a[] {4, 1, 6, 7, 8};


	//Sort:
	sort(a + 0, a + 5);//nlogn computation
	reverse(a, a + 5);//n computation


	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}


	cout << max(5, 7) << endl;
	cout << max(5, max(8, 9)) << endl;
	cout << max(1, max(5, max(13, max(19, max(20, 24)))));
	cout << max({1, 5, 6, 69, 19, 78, 62}) << endl;
	cout << min({1, 2, 3, 3, 4, 5, 5, 6, 89, 9, 9});


	int ans = INT_MIN;
	for (int i = 0; i < 5; i++) {
		ans = max(a[i], ans);
	}
	cout << endl;


	//This returns an address
	cout << *max_element(a, a + 5) << endl;
	cout << *min_element(a, a + 5) << endl;


	int *p = max_element(a, a + 5);







}