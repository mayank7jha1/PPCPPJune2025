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



	/*
		Now since we are at the center with i,j
		we need to fill the maximum character
		required in the center in order to make
		the lexographically smallest string
		.Also if you have used all the charaacter
		of k you can put a in all ? marks.
	*/
	// i--, j++;

	while (i >= 0) {

		//Identify the largest character not
		//used from first k characters.

		while (k > 1 and map[k] > 0) {
			k--;
		}

		//We have now the largest un used
		//character in 1 - k range.

		if (s[i] == '?' and s[j] == '?') {
			s[i] = s[j] = k + 'a' - 1;

		}

		i--, j++;
	}

	if (k == 1 and map[k] > 0) {
		cout << s << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}

















}