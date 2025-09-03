#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e3 + 1;
int k;
int dp[N];
int pre[N];
#define mod 1000000007

/*
	Dp[i] :F(i) : Number of ways to eat i flowers.
	pre[i] : Number of ways to eat flowers from 0 to i.

	Computation : 10^5+10^5 = 2*10^5 * 1

*/

int F(int n) {

	//Currently we are solving for state F(n).
	if (n == 0) {
		//Total ways to eat 0 flowers from 0 flowers is 1.
		return 1;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	//when the current flower you put at nth index is red.
	int Op1 = F(n - 1);


	//when the current flower you put at nth index is white.
	int Op2 = 0;//Least ways can only be 0.

	if (n - k >= 0) {
		Op2 = F(n - k);
	}

	return dp[n] = Op1 + Op2;
}

void Precomputation() {
	memset(dp, -1, sizeof(dp));
	pre[0] = 1;

	for (int i = 1; i < N; i++) {
		pre[i] = ((pre[i - 1] % mod) + (F(i) % mod)) % mod;
	}
}


int main() {

	int t;
	cin >> t >> k;
	Precomputation();

	while (t--) {

		int a, b;
		cin >> a >> b;
		cout << (pre[b] - pre[a - 1] + mod) % mod << endl;
	}
}






