#include<iostream>
#include"../Header_Files/Vector.h"
using namespace std;


int main() {

	Vector<int>v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

}