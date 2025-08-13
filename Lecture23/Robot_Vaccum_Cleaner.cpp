#include<iostream>
#include<algorithm>
using namespace std;
#define int long long


int Noise(string &s) {
	int sc = 0;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 's') {
			sc++;
		} else {
			ans += sc;
		}
	}
	return ans;
}

bool compare(string x, string y) {

	string xy = x + y;
	string yx = y + x;

	if (Noise(xy) > Noise(yx)) {
		return true;
	} else {
		return false;
	}

}

int32_t main() {

	int n;
	cin >> n;
	//This is an array of string type.
	string s[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	sort(s, s + n, compare);

	string final = "";
	for (int i = 0; i < n; i++) {
		final = final + s[i];
	}

	cout << Noise(final) << endl;

}