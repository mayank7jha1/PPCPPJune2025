#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<set>
using namespace std;

template<typename T>
class TreeNode {
public:
	T val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() {
		left = nullptr;
		right = nullptr;
	}

	TreeNode(T x) {
		val = x;
		left = nullptr;
		right = nullptr;
	}
};



TreeNode<int>*BuildTree() {
	int x;
	cin >> x;

	if (x == -1) {
		return NULL;
	} else {

		TreeNode<int>*n = new TreeNode<int>(x);
		n->left = BuildTree();
		n->right = BuildTree();

		return n;
	}
}

void bfs2(TreeNode<int>*root) {

	queue<TreeNode<int>*>q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {

		TreeNode<int>*f = q.front();
		q.pop();

		if (f == NULL) {

			if (!q.empty()) {
				q.push(NULL);
			}

			cout << endl;

		} else {

			cout << f->val << " ";

			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}

		}

	}
}


//Column Wise,Level Wise,Value Wise Sorted
void dfs(TreeNode<int>*root, map<int, multimap<int, int>>&mp1, int column, int level) {

	if (root == NULL) {
		return;
	}

	//Since We want Level wise sorted also preorder is imp.
	mp1[column].insert({level, root->val});


	dfs(root->left, mp1, column - 1, level + 1);
	dfs(root->right, mp1, column + 1, level + 1);
	return;
}

vector<int>VerticalView(TreeNode<int>*root) {
	vector<int>ans;

	// map<column_No,multimap of level and values>mp;
	map <int, multimap<int, int>>mp;

	if (root == NULL) {
		return ans;
	}

	dfs(root, mp, 0, 0);

	for (pair<int, multimap<int, int>> x : mp) {
		for (pair<int, int>y : x.second) {
			ans.push_back(y.second);
		}
	}

	return ans;
}


int main() {

	TreeNode<int>*root = BuildTree();
	bfs2(root);

	vector<int>a = VerticalView(root);
	for (int x : a) {
		cout << x << " ";
	}
	cout << endl;
}