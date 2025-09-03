#include<iostream>
#include<cstring>
using namespace std;

/*
	Computation : 1001*1001*1+1001

*/
int dp[1001][1001];

string getLCS(string &s, string &t, int i, int j, int LCS) {

	string ans = "";


	while (LCS > 0) {

		if (s[i] == t[j]) {
			ans.push_back(s[i]);
			i++; j++;
			LCS--;

		} else if (dp[i + 1][j] > dp[i][j + 1]) {
			i++;
		} else {
			j++;
		}
	}

	return ans;

}



int F1(string &s, string &t, int i, int j) {

	if (i == s.length() or j == t.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		return dp[i][j] = 1 + F1(s, t, i + 1, j + 1);

	} else {

		int Op1 = F1(s, t, i + 1, j);
		int Op2 = F1(s, t, i, j + 1);

		return dp[i][j] = max(Op1, Op2);
	}

}


string longestCommonSubsequence(string s, string t) {
	memset(dp, -1, sizeof(dp));
	int lengthLCS = F1(s, t, 0, 0);
	return getLCS(s, t, 0, 0, lengthLCS);
}

int main() {

	string s, t;
	cin >> s >> t;
	cout << longestCommonSubsequence(s, t) << endl;
}