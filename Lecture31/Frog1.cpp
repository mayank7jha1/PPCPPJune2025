#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int n;
int a[200001];
int dp[100004];
// vector<int>dp(100004, -1);

//Computation : (10^5*1)
//dp[i] : Min cost from 1st stone to ith stone.


int F(int i) {

	//Stopping Point:
	if (i == n) {
		return 0;
	}

	if (dp[i] != -1) {
		return dp[i];
	}

	int Op1 = abs(a[i] - a[i + 1]) + F(i + 1);

	int Op2 = INT_MAX;
	if (i + 2 <= n) {
		//When you take two step jump.
		Op2 = abs(a[i] - a[i + 2]) + F(i + 2);
	}

	//Current state answer : i.e. F(i) will be :
	return dp[i] = min(Op1, Op2);
}


int main() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	memset(dp, -1, sizeof(dp));

	cout << F(1) << endl;
}