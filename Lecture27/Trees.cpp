#include<iostream>
#include<algorithm>
#include<climits>
#include"../Header_Files/Trees.h"
using namespace std;


int main() {

	/*
		TreeNode<int>*root = BuildTree();
		Preorder(root);
		cout << endl;
		Inorder(root);
		cout << endl;
		Postorder(root);
		cout << endl;

		cout << Height(root) << endl;
		cout << CountNodes(root) << endl;
		cout << SumofNodes(root) << endl;
		Mirror(root);

		Preorder(root);
		cout << endl;
		cout << Diameter1(root) << endl;
		cout << HeightDiameter(root) << endl;
		cout << d << endl;
		cout << Diameter3(root).diameter << " " << Diameter3(root).height << endl;
		cout << IsheightBalanced(root).first << " " << IsheightBalanced(root).second << endl;

		int n = 10;
		int a[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		TreeNode<int>*root1 = BuildTreeheightbalanced(a, 0, n - 1);
		Preorder(root1);
		cout << endl;
		cout << IsheightBalanced(root1).first << " " << IsheightBalanced(root1).second << endl;

		PrintKthLevel(root, 2);
		cout << endl << endl;
		PrintALLLevel(root);
		cout << endl;
		bfs(root);
		cout << endl;
		bfs2(root);
		cout << endl;

		int pre[] {1, 2, 4, 5, 3, 7};
		int in[] {4, 2, 5, 1, 3, 7};
		int n1 = 6;

		TreeNode<int>*root3 = BuildTreeFromPreAndIn(pre, in, 0, n1 - 1);
		bfs2(root3);

		PrintAllLevelUsingBfs(root);

		for (vector<int> x : ans) {

			for (int y : x) {
				cout << y << " ";
			}
			cout << endl;
		}

		cout << endl;

		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i][0] << " ";
		}

		cout << endl;

		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i][ans[i].size() - 1] << " ";
		}

		cout << endl;

		int x = -1;

		LeftView(root, 1, x);
		cout << endl;
		cout << x << endl;
		x = -1;
		Rightview(root, 1, x);
		cout << endl;

		TreeNode<int>*root4 = BuildBst();
		bfs2(root4);
		cout << endl;
		cout << SearchInBst(root4, 17) << endl;
		leftview2(root);
		cout << endl;

	*/

	/*
		This is the Tree I have taken input for various functions below like:
		1.takeInputLevel
		2.buildFromBfs2
		3.buildFromBfs

						            1
					              /   \
					            2       3
					          /   \   /   \
					        4     10 9     11
					         \
					          5
					           \
					            6

	*/


	/*
		Input Format for Take Input Level Function.
		1
		2 3
		4 10 9 11
		-1 5 -1 -1 -1 -1 -1 -1
		-1 6
	*/

	/*
		TreeNode<int>*root5 = takeInputLevel();
		bfs2(root5);
	*/

	/*
		vector<int>a1{1, 2, 3, 4, 10, 9, 11, -1, 5, -1, -1, -1, -1, -1, -1, -1, 6};
		TreeNode<int>*root6 = buildFromBfs2(a1);
		bfs2(root6);
	*/

	/*
		vector<int>a{1, 2, 3, 4, 10, 9, 11, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6};
		TreeNode<int>*root7 = buildFromBfs(a, 0);
		bfs2(root7);
	*/
}