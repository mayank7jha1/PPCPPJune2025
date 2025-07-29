#include<iostream>
using namespace std;
#define int long long
int n, h, l, r;
int a[2001];


/*
	F(i,wt): maximum sleep from i to n-1 where the current waking time
	is wt.

	//Recursion : no of states * transition time.
	//dp : No of unique states * transition time.

	Computations: (2^n * constant) ~ 2^n.


*/

int F(int i, int wt) {

	//Currently we are calculating for the state F(i,wt).

	if (i == n) {
		// F(n,t): 0;
		return 0;
	}

	//This is only going to tell you if the next sleep is good or not.
	int ans1 = 0, ans2 = 0;

	int Nwtop1 = (wt + a[i]) % h;
	int Nwtop2 = (wt + a[i] - 1) % h;


	if (Nwtop1 >= l and Nwtop1 <= r) {
		ans1 = 1;
	}

	if (Nwtop2 >= l and Nwtop2 <= r) {
		ans2 = 1;
	}


	//When you sleep after a[i] hours.
	int Op1 = ans1 + F(i + 1, Nwtop1);

	//When you sleep after (a[i]-1) hours.
	int Op2 = ans2 + F(i + 1, Nwtop2);

	return max(Op1, Op2);
}


int32_t main() {

	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << F(0, 0) << endl;
}




//https://hack.codingblocks.com/app/contests/8153/281/problem