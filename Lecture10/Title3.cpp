#include<iostream>
using namespace std;


int main() {

	int k;
	cin >> k;
	char s[105];
	cin >> s;
	int len = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		len++;
	}

	int map[27] {0};

	int i = 0, j = len - 1;
	while (i <= j) {
		if (s[i] == '?' and s[j] == '?') {
			i++, j--;
		} else if (s[i] == '?' and s[j] != '?') {
			s[i] = s[j];
			char element = s[i];
			//1 is added for 1 based indexing.
			map[element - 'a' + 1]++;
			i++, j--;
		} else if (s[i] != '?' and s[j] == '?') {
			s[j] = s[i];
			map[s[i] - 'a' + 1]++;
			i++, j--;
		} else if (s[i] == s[j]) {
			map[s[i] - 'a' + 1]++;
			i++, j--;
		} else {
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
	}

	i--, j++;

	while (i >= 0) {

		while (k > 1 and map[k] > 0) {
			k--;
		}



		if (s[i] == '?' and s[j] == '?') {
			s[i] = s[j] = k + 'a' - 1;
			map[k]++;
		}

		i--, j++;
	}

	if (k == 1 and map[k] > 0) {
		cout << s << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}

















}