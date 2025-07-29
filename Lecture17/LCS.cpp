#include<iostream>
using namespace std;

/*

	class Solution {
	public:
	    string p,l;
	    int F1(int i,int j){

	    }
	    int longestCommonSubsequence(string s, string t) {
	        p=s,l=t;
	        return F1(0,0);
	    }
	};

*/
int dp[1001][1001];

int F1(string &s, string &t, int i, int j) {

	if (i == s.length() or j == t.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		// int Op1 = 1 + F1(i + 1, j + 1);
		return dp[i][j] = 1 + F1(s, t, i + 1, j + 1);

	} else {
		/*
			If this occurs you are sure both
			s[i] and t[j] cannot be part of the LCS
			together.

			that means: either s[i] is part of LCS,or
			t[j] is part of LCS or both are not part of lcs

			we are making op1 and op2 to take care of 1 and 2
			portion saying the 3 one where s[i] and t[j] both
			are not part of lcs will be automatically taken care of
			.

			if you want you can always write the 3rd scenario
			but will be incr. the computations.

		*/
		//You are skipping the character from s string.
		int Op1 = F1(s, t, i + 1, j);

		//You are skipping the character from t string.
		int Op2 = F1(s, t, i, j + 1);

		return dp[i][j] = max(Op1, Op2);
	}

}


int longestCommonSubsequence(string s, string t) {
	memset(dp, -1, sizeof(dp));
	return F1(s, t, 0, 0);
}

int main() {

	string s, t;
	cin >> s >> t;


	cout << longestCommonSubsequence(s, t) << endl;

}