#include<iostream>
using namespace std;
int k;

int F(int n) {

	//Currently we are solving for state F(n).
	if (n == 0) {
		//Total ways to eat 0 flowers from 0 flowers is 1.
		return 1;
	}


	//when the current flower you put at nth index is red.
	int Op1 = F(n - 1);


	//when the current flower you put at nth index is white.
	int Op2 = 0;//Least ways can only be 0.

	if (n - k >= 0) {
		Op2 = F(n - k);
	}

	return Op1 + Op2;
}



int main() {
	int n;
	cin >> n >> k;
	cout << F(n);
}

F(4) = 5;
F(3) = 3;
F(2) = 2;
F(1) = 1;







