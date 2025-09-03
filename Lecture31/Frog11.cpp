#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int n;
int a[200001];
int dp[100004];
// vector<int>dp(100004, -1);

//Computation : (10^5*1)
//dp[i] : Min cost from nth stone to ith stone.


int F(int n) {

	//Stopping Point:
	if (n == 1) {
		return 0;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int Op1 = abs(a[n] - a[n - 1]) + F(n - 1);

	int Op2 = INT_MAX;
	if (n - 2 >= 1) {
		//When you take two step jump.
		Op2 = abs(a[n] - a[n - 2]) + F(n - 2);
	}

	//Current state answer : i.e. F(i) will be :
	return dp[n] = min(Op1, Op2);
}


int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << F(n) << endl;
}