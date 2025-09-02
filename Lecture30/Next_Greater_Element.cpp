#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        stack<int>st;
        map<int, int>mp;//This is for faltu leetcode work.

        st.push(INT_MAX);

        for (int i = nums2.size() - 1; i >= 0; i--) {

            int currentElement = nums2[i];

            while (currentElement >= st.top()) {
                st.pop();
            }


            if (st.top() == INT_MAX) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }

            st.push(currentElement);
        }

        vector<int>ans;
        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    };


    int main() {



    }