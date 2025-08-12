
#include<iostream>
using namespace std;



class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>&c, int t) {

    }
};




int main() {

    int n;
    cin >> n;
    vector<int>input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int target;
    cin >> target;

    Solution s;
    vector<vector<int>>ans = s.combinationSum(input, target);

    //Print this ans:


}