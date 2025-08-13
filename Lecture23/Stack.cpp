#include<iostream>
#include"../Header_Files/Stack.h"
using namespace std;


int main() {

	Stack<int>st;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int s;
		cin >> s;
		st.push(s);
	}

	while (st.empty() == 0) {
		cout << st.top() << endl;
		st.pop();
	}


}