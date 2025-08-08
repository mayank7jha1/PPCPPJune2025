#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>ans;
vector<int>current;

void F(vector<int>&a, int index, int  target) {

	if (index == a.size()) {
		if (target == 0) {
			ans.push_back(current);
		}
		return;
	}

	//Choose the current element
	if (a[index] <= target) {
		current.push_back(a[index]);

		F(a, index, target - a[index]);

		//If I am standing here :
		current.pop_back();
	}

	//Not Choose
	F(a, index + 1, target);

	return;
}



vector<vector<int>> combinationSum(vector<int>& a, int target) {
	F(a, 0, target);
	return ans;
}


int main() {


}