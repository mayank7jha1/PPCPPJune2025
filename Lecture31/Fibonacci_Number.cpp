#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;


/*

	Idea: If it is a unique state calculate its answer and store it in a effective way.
	If its not then with the help previously calculated state return the answer.

	Definition of DP: dp[n] : It stores the answer for f(n) state.
	dp[n] = dp[n-1]+dp[n-2];

	dp[0]=f(0)=0
	dp[1]=f(1)=1

	dp array ko aapko ek aisi value se initialise karna hain jo kabhi answer
	nahi bann sakti.

	Recursion + Memoisaton: Calculate karne se pehle check and return karne se
	pehle store in recursion.


	Computation : No of states/Unique States * Transition Time :
	 ~(n+1*1) ~ n

*/




int F(int n, int *dp) {

	if (n == 0 or n == 1) {
		return n;
	}

	//If I am here : I will start the calculation for the current state.
	//Calculate karne se pehle check karo ki aapne current state ka answer kahi
	//pehle to nahi nikal liya.

	if (dp[n] != -1) {
		return dp[n];
	}

	int Op1 = F(n - 1, dp);
	int Op2 = F(n - 2, dp);

	//Store the answer for the current state : Before Returning :
	//Return karne se pehle store.
	return dp[n] = (Op1 + Op2);
}



int F1(int n, int *dp) {

	//dp[i] : ith Fibonacci number.

	//Base Condition for Recursion.
	dp[0] = 0;
	dp[1] = 1;


	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[i];
}


int main() {

	int n;
	cin >> n;
	int dp[n + 1];
	int dp1[n + 1] {0};
	memset(dp, -1, sizeof(dp));

	cout << F(n, dp) << endl;
	cout << F1(n, dp1) << endl;

}