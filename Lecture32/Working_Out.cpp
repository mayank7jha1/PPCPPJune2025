#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

/*
	dp1[x][y] : Max. Calorie from 1,1 to x,y;
	dp2[x][y] : Max. Calorie from n,m to x,y;

	dp3[x][y] : Max. calorie from n,1 to x,y
	dp4[x][y] : Max. Calorie from 1,m to x,y.

*/

const int N = 1001;
int dp1[N][N] {0};
int dp2[N][N] {0};
int dp3[N][N] {0};
int dp4[N][N] {0};


int n, m;
int Calorie[N][N] {0};


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Calorie[i][j];
		}
	}

	//Build All Dp arrays:
	//Dp1: Max calorie from 1,1 to x,y.

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (i == 1 and j == 1) {
				dp1[i][j] = Calorie[i][j];
			} else if (i == 1) {
				dp1[i][j] = dp1[i][j - 1] + Calorie[i][j];
			} else if (j == 1) {
				dp1[i][j] = dp1[i - 1][j] + Calorie[i][j];
			} else {
				dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + Calorie[i][j];
			}

		}
	}

	//Dp2 : Max. Calorie from n,m to x,y;
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {

			if (i == n and j == m) {
				dp2[i][j] = Calorie[i][j];
			} else if (i == n) {
				dp2[i][j] = dp2[i][j + 1] + Calorie[i][j];
			} else if (j == m) {
				dp2[i][j] = dp2[i + 1][j] + Calorie[i][j];
			} else {
				dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]) + Calorie[i][j];
			}

		}
	}


	//Dp3 : Maximum Calorie from n,1 to x,y.

	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {

			if (i == n and j == 1) {
				dp3[i][j] = Calorie[i][j];
			} else if (i == n) {
				dp3[i][j] = dp3[i][j - 1] + Calorie[i][j];
			} else if (j == 1) {
				dp3[i][j] = dp3[i + 1][j] + Calorie[i][j];
			} else {
				dp3[i][j] = max(dp3[i + 1][j], dp3[i][j - 1]) + Calorie[i][j];
			}

		}
	}

	//Dp4 : Maximum Calorie from 1,n to x,y:

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {

			if (i == 1 and j == m) {
				dp4[i][j] = Calorie[i][j];
			} else if (i == 1) {
				dp4[i][j] = dp4[i][j + 1] + Calorie[i][j];
			} else if (j == m) {
				dp4[i][j] = dp4[i - 1][j] + Calorie[i][j];
			} else {
				dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + Calorie[i][j];
			}

		}
	}


	//Logic:
	int ans = INT_MIN;

	for (int x = 2; x <= n - 1; x++) {
		for (int y = 2; y <= m - 1; y++) {

			//We are assuming x,y as the meeting point.

			int Op1 = dp1[x - 1][y] + dp2[x + 1][y] + dp3[x][y - 1] + dp4[x][y + 1];
			int Op2 = dp1[x][y - 1] + dp2[x][y + 1] + dp3[x + 1][y] + dp4[x - 1][y];

			int value = max(Op1, Op2);
			ans = max(value, ans);
		}
	}


	cout << ans << endl;


}