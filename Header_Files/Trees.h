#include<iostream>
#include<queue>
#include"../Header_Files/TreeNode.h"
using namespace std;


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

void Preorder(TreeNode<int>*root) {

	if (root == NULL) {
		return;
	}

	cout << root->val << " ";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(TreeNode<int>*root) {

	if (root == NULL) {
		return;
	}

	Inorder(root->left);
	cout << root->val << " ";
	Inorder(root->right);
}

void Postorder(TreeNode<int>*root) {

	if (root == NULL) {
		return;
	}

	Postorder(root->left);
	Postorder(root->right);
	cout << root->val << " ";
}

int Height(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	/*
		Since We have to travel to every
		node in order for us to calculate the
		height we can follow any of the tree traversal preorder,postorder,inorder.
		But the most common one that you are going to see
		is post order traversal.
	*/

	int LSH = Height(root->left);
	int RSH = Height(root->right);

	return 1 + max(LSH, RSH);
}

int CountNodes(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	int LSN = CountNodes(root->left);
	int RSN = CountNodes(root->right);

	return 1 + LSN + RSN;
}

int SumofNodes(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	int LSS = SumofNodes(root->left);
	int RSS = SumofNodes(root->right);

	return (root->val + LSS + RSS);
}

void Mirror(TreeNode<int>*root) {

	if (root == NULL) {
		return;
	}

	swap(root->left, root->right);
	Mirror(root->left);
	Mirror(root->right);

}

int Diameter1(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	int Op1 = Diameter1(root->left);
	int Op2 = Diameter1(root->right);
	int Op3 = Height(root->left) + Height(root->right);

	return max({Op1, Op2, Op3});
}

//Calculation of Diameter 2: Optimisation
int d = 0;
int HeightDiameter(TreeNode<int>*root) {

	if (root == NULL) {
		return 0;
	}

	int LSH = HeightDiameter(root->left);
	int RSH = HeightDiameter(root->right);


	//Calculation of my diameter:
	d = max(d, LSH + RSH);

	//Calculate and return the height as usual
	return 1 + max(LSH, RSH);
}

//Third Implementation : Diamter 3:
class Pair {
public:
	int diameter;
	int height;

	Pair() {
		height = 0;
		diameter = 0;
	}
};

//~n Computation
Pair x;

Pair Diameter3(TreeNode<int>*root) {

	if (root == NULL) {
		x.diameter = 0;
		x.height = 0;
		return x;
	}

	Pair LSI = Diameter3(root->left);
	Pair RSI = Diameter3(root->right);

	//Calculating the height till the current node.
	x.height = 1 + max(LSI.height, RSI.height);


	//Diameter till now:
	x.diameter = max({LSI.diameter, RSI.diameter,
	                  LSI.height + RSI.height
	                 });

	return x;
}

//Check if the given tree is height balanced or not?

// pair<height,yaha tak ka tree height balanced hain ke nahi>
pair<int, bool>y;
pair<int, bool>IsheightBalanced(TreeNode<int>*root) {

	if (root == NULL) {
		y.second = 1;
		y.first = 0;
		return y;
	}

	pair<int, bool>LSI = IsheightBalanced(root->left);
	pair<int, bool>RSI = IsheightBalanced(root->right);


	//Calculation of height:
	y.first = 1 + max(LSI.first, RSI.first);

	//Calculation if the tree till this node is height balanced or not.

	if (LSI.second == 1 and RSI.second == 1 and
	        abs(LSI.first - RSI.first) <= 1) {
		y.second = 1;
	} else {
		y.second = 0;
	}

	return y;
}

TreeNode<int>*BuildTreeheightbalanced(int *a, int s, int e) {

	if (s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	TreeNode<int>*root = new TreeNode<int>(a[mid]);

	root->left = BuildTreeheightbalanced(a, s, mid - 1);
	root->right = BuildTreeheightbalanced(a, mid + 1, e);

	return root;
}

void PrintKthLevel(TreeNode<int>*root, int k) {

	if (root == NULL) {
		return;
	}

	if (k == 1) {
		cout << root->val << " ";
		return;
	}

	PrintKthLevel(root->left, k - 1);
	PrintKthLevel(root->right, k - 1);
}

//Computation: n*n
void PrintALLLevel(TreeNode<int>*root) {

	int H = Height(root);

	for (int i = 1; i <= H; i++) {
		PrintKthLevel(root, i);
		cout << endl;
	}

}

void bfs(TreeNode<int>*root) {

	queue<TreeNode<int>*>q;
	q.push(root);

	while (!q.empty()) {

		TreeNode<int>*f = q.front();
		q.pop();

		cout << f->val << " ";

		if (f->left != NULL) {
			q.push(f->left);
		}

		if (f->right != NULL) {
			q.push(f->right);
		}
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