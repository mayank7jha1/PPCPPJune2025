#include<iostream>
using namespace std;
#define int long long
int n, k;
const int N = 1e5 + 1;
int a[N] {0};
#define mod 1000000007
int dp[102][N] {{0}};

/*
	dp[i][j] : Number of ways to distribute j candies amoung i children.
*/


int F() {

	//Base Condition :
	for (int j = 0; j <= k; j++) {
		if (j <= a[1]) {
			dp[1][j] = 1;
		} else {
			dp[1][j] = 0;
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {

			int Part1 = 0;
			if (j > 0) {
				Part1 = dp[i][j - 1] % mod;
			}

			int Part2 = 0;
			if (j - a[i] - 1 >= 0) {
				Part2 = dp[i - 1][j - a[i] - 1] % mod;
			}

			int Part3 = dp[i - 1][j] % mod;

			dp[i][j] = (Part1 - Part2 + Part3) % mod;
		}
	}


	return (dp[n][k] % mod);
}



int32_t main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << F() << endl;


}