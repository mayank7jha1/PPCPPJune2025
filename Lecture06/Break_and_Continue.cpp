#include<iostream>
using namespace std;



//Jump Statements:
//Break and Continue:

int main() {

	//repeat: Jump statements

	// for (int i = 0; i < 10; i++) {

	// 	if (i == 3) {
	// 		break;
	// 	}

	// 	cout << i << endl;

	// }
	// cout << "Hi" << endl;
	// int count = 0;

	// for (int i = 0; i < 10; i++) {

	// 	for (int j = 0; j < 10; j++) {
	// 		if (j == 4) {
	// 			break;
	// 			cout << "I am good.";
	// 		}
	// 		count++;
	// 	}

	// 	break;

	// }

	// cout << count << endl;


	// 90(Wrong ans)
	// 40
	// 49
	// 39
	// 50

	int count = 0;

	// for (int i = 0; i < 10; i++) {
	// 	if (i == 4) {
	// 		continue;
	// 		cout << "Yo";
	// 	}

	// 	count++;
	// }

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 4) {
				continue;
				cout << "yyihih";
			}
			count++;
		}

	}

	//90



}