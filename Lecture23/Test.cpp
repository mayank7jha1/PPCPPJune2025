#include<iostream>
#include<algorithm>
using namespace std;



class Info {
public:
	string name;
	int money;

	//Default Constructor
	Info() {
		money = 0;
		name = "";
	}

	//Parameterised Constructor
	Info(string x, int money) {
		name = x;
		this->money = money;
	}
};



bool compare(Info c, Info d) {
	if (c.money > d.money) {
		return true;
	} else {
		return false;
	}
}



int main() {
	int n;
	cin >> n;

	//This is an array of info data type.
	Info a[n];
	for (int i = 0; i < n; i++) {
		// string s;
		// int x;
		// cin >> s >> x;
		// a[i].name = s;
		// a[i].money = x;
		cin >> a[i].name >> a[i].money;
	}

	//If I want to sort the current data on the
	// basis of money.

	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		cout << a[i].name << " " << a[i].money << endl;
	}

}