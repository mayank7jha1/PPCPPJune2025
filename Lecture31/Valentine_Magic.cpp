#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
const int N = 1e6 + 3;
#define int long long

int n, m;
int b[N];
int g[N];
int dp[5002][5002];

//Computations : 5001*5001*1


/*
	F(i,j): Minimum sum by choosing boys from i to n-1 and girls
	from j to m-1.
*/

int F(int i, int j) {

	//Currently we are solving for the state F(i,j).
	if (i == n) {
		//F(n,j): this is a valid path.
		return 0;
	}

	if (j == m) {
		//F(i,m) : this is not a valid path.
		return INT_MAX;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	//I choose the current girl.
	int Op1 = abs(b[i] - g[j]) + F(i + 1, j + 1);

	//I will not choose the current girl.
	int Op2 = 0 + F(i, j + 1);

	return dp[i][j] = min(Op1, Op2);
}

int32_t main() {


	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> g[i];
	}

	memset(dp, -1, sizeof(dp));

	sort(b, b + n);//Asc. order sort.
	sort(g, g + m);//Asc. order sort.

	cout << F(0, 0) << endl;
}