#include<iostream>
#include<algorithm>
using namespace std;

// void name() {
// 	//It takes the input data for names.
// }

// void atul() {

// 	name();//This should not be allowed.


// }

int main() {

	int n;
	cin >> n;

	//DS: Two arrays me relationship establish aapne kiya hain.
	//This makes your program fast.
	string name[n];
	int money[n] {0};
	int height[n];
	int money_index[n] {0};

	for (int i = 0; i < n; i++) {
		cin >> name[i] >> money[i];
	}

	//Execution Ka kaam karna hain bas.
	int i;
	for (i = 0; i < n; i++) {
		if (name[i] == "mayank") {
			break;
		}
	}

	cout << money[i] << endl;

	//Ascending order me sort karega.
	sort(money, money + n);
	//To make the money array in desc. order.
	reverse(money, money + n);

	//Compiler is still expecting ki aap relationship firse establish karo.
	for (int i = 0; i < n; i++) {
		cout << name[i] << " " << money[i] << endl;
	}

}

// Mayank 100   5
// Samyak 200  4




// Samyak 200 4
// Mayank 100 5



