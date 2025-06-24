#include<iostream>
using namespace std;


int main() {

	int m, n, a;
	cin >> m >> n >> a;

	long long int ans = ((m + a - 1) / a) * ((n + a - 1) / a);

	cout << ans << endl;


	// int : ~+- 10^9
	// long/ long int : +- 10^12
	// long long int : +- 10^18

}