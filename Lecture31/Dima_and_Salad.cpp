#include<iostream>
#include<cstring>
using namespace std;
const int N = 101;
const int shift = 1e5 + 1;
int n, k;
int taste[N], calorie[N];
int dp[N][200004] {{0}};
// map<pair<int, int>, int>mp;
#define int long long

//dp[i][sum] : Maximum taste from 0th fruit to ith fruit where the
// sum of the chosen fruits is stored in variable sum. which is nothing but F(i,sum).
//we are taking shift because the sum can be -ve.

//Computations: 101*200004*1

int F(int i, int sum) {
	//Currently We are solving for F(i,sum)

	if (i == n) {

		if (sum == 0) {
			return 0;//I have found a valid path.
		} else {
			return -1e9;//This is an unvaid path.
		}
	}

	if (dp[i][shift + sum] != -1) {
		return dp[i][shift + sum];
	}

	//To choose the current fruit:
	int Op1 = taste[i] + F(i + 1,
	                       sum + (taste[i] - k * calorie[i]));


	//To not choose the current fruit.
	int Op2 = 0 + F(i + 1, sum);

	return dp[i][shift + sum] = max(Op1, Op2);
}


int32_t main() {

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = F(0, 0);

	if (ans <= 0) {
		cout << "-1" << endl;
	} else {
		cout << ans << endl;
	}

}


