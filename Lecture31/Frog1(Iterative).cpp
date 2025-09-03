#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int n;
int a[200001];
int dp[100004] {0};
// vector<int>dp(100004, -1);

//Computation : (10^5*1)
//dp[i] : Min cost from 1st stone to ith stone.
//dp[i] : min(Ex1+dp[i-1],Ex2+dp[i-2])


int F(int n) {

	dp[1] = 0;
	dp[2] = a[2] - a[1];


	for (int i = 3; i <= n; i++) {

		int op1 = abs(a[i] - a[i - 1]) + dp[i - 1];
		int op2 = abs(a[i] - a[i - 2]) + dp[i - 2];

		dp[i] = min(op1, op2);
	}

	return dp[n];
}


int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << F(n) << endl;
}