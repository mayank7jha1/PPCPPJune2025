#include<iostream>
using namespace std;
const int N = 1e5 + 3;//1*10^5+3
char st[N];
int n, k;
// int countop = 0;


int F(char op) {

	int s = 0;
	int countop = 0;
	int maxi = INT_MIN;




	for (int e = 0; e < n; e++) {
		//Expansion:
		if (st[e] == op) {
			countop++;
		}

		//If You are at undesired Window:
		//Shrinking:

		while (s <= e and countop > k) {

			if (st[s] == op) {
				countop--;
			}
			s++;
		}

		//Whenever you are in desired window:
		if (maxi < (e - s + 1)) {
			maxi = (e - s + 1);
		}

	}

	return maxi;
}


int main() {

	cin >> n >> k;
	cin >> st;


	//Current Operation to Perform : b->a
	int ans1 = F('b');
	// cout << countop << endl;
	// cout << maxi << endl;

	//Current Operation to Perform : a->b
	int ans2 = F('a');

	if (ans1 > ans2) {
		cout << ans1 << endl;
	} else {
		cout << ans2 << endl;
	}

}