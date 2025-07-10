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

	/*
		This is working as freq array.
		This freq array is one based.
		a is mapped at 1 index and z is mapped at 26 index.
	*/

	int map[27] {0};

	/*
		First task is to scan and fill those
		boxes where we know the answer directly.
		While doing this also maintain which all
		characters you have used.
	*/

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

	// //Special Case for odd length string.
	// if (i == j and s[i] != '?') {
	// 	map[s[i] - 'a' + 1]++;
	// }


	//Now we need to fill double '?' marks.
	//from inside.

	//Currently my i is at the middle point.
	//and j is also at the middle point.

	//while (i >= 0)

	// cout << i << " " << j << endl;

	// for (int i = 1; i <= 26; i++) {
	// 	if (map[i] > 0) {
	// 		cout << char(i + 'a' - 1) << " " << map[i] << endl;
	// 	}
	// }













}