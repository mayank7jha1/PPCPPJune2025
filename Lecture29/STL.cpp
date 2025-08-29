#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;


int main() {


	//priority_queue<int>st;//THis is a Max Priority Heap
	priority_queue<int, vector<int>, greater<int>>st;//Min Priority Queue
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>mp1;

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