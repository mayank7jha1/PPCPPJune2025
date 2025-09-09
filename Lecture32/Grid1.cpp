#include<iostream>
#include<cstring>
using namespace std;
char grid[101][101];
#define mod 1000000007


int TW1(int h, int w) {

	//dp[i][j] : Total ways till i,j from h,w;
	int dp[101][101] {0};

	if (grid[1][1] == '#' or grid[h][w] == '#') {
		return 0;
	}

	for (int i = h; i >= 1; i--) {
		for (int j = w; j >= 1; j--) {

			if (i == h and j == w) {
				dp[i][j] = 1;
				continue;
			}

			if (grid[i][j] == '#') {
				dp[i][j] = 0;
				continue;
			}


			if (i == h) {
				dp[i][j] = dp[i][j + 1] % mod;
				continue;
			}

			if (j == w) {
				dp[i][j] = dp[i + 1][j] % mod;
				continue;
			}


			dp[i][j] = (dp[i + 1][j] % mod + dp[i][j + 1] % mod) % mod;

		}
	}


	return dp[1][1];
}


int TW2(int x, int y, int h, int w) {

	//dp[i][j] : Total ways till i,j from 1,1;
	int dp[101][101] {0};

	if (grid[1][1] == '#' or grid[h][w] == '#') {
		return 0;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {

			if (i == 1 and j == 1) {
				dp[i][j] = 1;
				continue;
			}

			if (grid[i][j] == '#') {
				dp[i][j] = 0;
				continue;
			}


			if (i == 1) {
				dp[i][j] = dp[i][j - 1] % mod;
				continue;
			}

			if (j == 1) {
				dp[i][j] = dp[i - 1][j] % mod;
				continue;
			}


			dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;

		}
	}


	return dp[h][w];
}


int dp1[101][101];

int TWR(int x, int y, int h, int w) {

	//F(x,y) : Total ways from h,w to x,y.
	if (x == h and y == w) {
		return 1;
	}

	if (dp1[x][y] != -1) {
		return dp1[x][y];
	}


	int Op1 = 0;
	if (y + 1 <= w) {
		Op1 = TWR(x, y + 1, h, w);
		Op1 %= mod;
	}

	int Op2 = 0;
	if (x + 1 <= h) {
		Op2 = TWR(x + 1, y, h, w);
		Op2 %= mod;
	}


	return dp1[x][y] = ((Op1 + Op2) % mod);
}



int main() {
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> grid[i][j];
		}
	}

	memset(dp1, -1, sizeof(dp1));
	cout << TW1(h, w) << endl;
	cout << TW2(1, 1, h, w) << endl;
	cout << TWR(1, 1, h, w) << endl;

}