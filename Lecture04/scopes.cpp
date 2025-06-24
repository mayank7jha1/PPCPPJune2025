#include<iostream>
using namespace std;
//Global Scope
const int a = 89;




int main() {

	cout << a << endl;

	int a{30};//Direct List Initialisation
	cout << a << endl;

	//a = a + 1;

	if (true) {
		//Local Scope
		const int a {78};
		cout << a << endl;
	}

	cout << a << endl;

}







