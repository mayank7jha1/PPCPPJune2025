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
		sum += a[index];
		current.push_back(a[index]);
		F(a, index, sum, target);
		sum -= a[index];
		current.pop_back();
	}

	return;
}

vector<vector<int>> combinationSum(vector<int>& a, int target) {
	int sum = 0;
	F(a, 0, 0, target);
	return ans;
}





