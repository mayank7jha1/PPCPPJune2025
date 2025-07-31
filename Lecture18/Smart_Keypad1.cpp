#include<iostream>
using namespace std;

string keypad[] { " ", ".+@$", "abc", "def", "ghi", "jkl" ,
	"mno", "pqrs" , "tuv", "wxyz"
};

char input[100];
char output[100];

void F(int i, int j) {

	if (input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}

	char ch = input[i];
	int index = ch - '0';

	for (int k = 0; k < keypad[index].length(); k++) {
		output[j] = keypad[index][k];
		F(i + 1, j + 1);
	}
}

int main() {
	cin >> input;
	F(0, 0);
}