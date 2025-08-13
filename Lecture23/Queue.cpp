#include<iostream>
#include"../Header_Files/Queue.h"
using namespace std;


int main() {


	int n;
	cin >> n;
	Queue<int>st;

	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		st.push(s);
	}

	while (st.empty() == 0) {
		cout << st.front1() << endl;
		st.pop();
	}

}