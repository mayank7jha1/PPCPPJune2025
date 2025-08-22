#include<iostream>
#include<algorithm>
#include"../Header_Files/Trees.h"
using namespace std;


int main() {

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
}