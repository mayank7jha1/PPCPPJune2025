#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>ans;
vector<int>current;
void F(vector<int>&a, int i, int sum, int  target) {

	if (sum == target) {
		ans.push_back(current);
		return;
	} else if (sum > target) {
		return;
	}

	//Currently We are solving for F(i,sum) state:
	for (int index = i; index < a.size(); index++) {
		sum += a[i];
		current.push_back(a[i]);

		F(a, i, sum, target);


		//If I am Standing Here that means either I have found
		//a solution and put that solution in answer vector
		//or I have not found a solution and in both
		//of the scenarios I will remove the current element
		//and look for a different answer.

		sum -= a[i];
		current.pop_back();
	}

	return;
}



vector<vector<int>> combinationSum(vector<int>& a, int target) {


	int sum = 0;
	F(a, 0, 0, target);
	return ans;
}


int main() {









}







// _ _ _ _ _ _

// a b c d e

// a+a+a+b+




