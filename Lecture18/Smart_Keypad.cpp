#include<iostream>
using namespace std;

string keypad[] { " ", ".+@$", "abc", "def", "ghi", "jkl" ,
	"mno", "pqrs" , "tuv", "wxyz"
};


// keypad[3]: 3rd index par jo string hain uski baat horahi
// hain. keypad[3] : def.

char input[100];
char output[100];

void F(int i, int j) {

	if (input[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}

	char ch = input[i];//This is a numeric character
	int index = ch - '0';

	/*	Op1: output[j] = keypad[index][0];
			F(i + 1, j + 1);
		Op2: output[j] = keypad[index][1];
			F(i + 1, j + 1);
		Op3: output[j] = keypad[index][2];
			F(i + 1, j + 1);
		Op4: output[j] = keypad[index][3];
			F(i + 1, j + 1);
	*/

	for (int k = 0; k < keypad[index].length(); k++) {
		output[j] = keypad[index][k];
		F(i + 1, j + 1);
	}
}

int main() {

	cin >> input;
	F(0, 0);
}