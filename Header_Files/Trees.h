#include<iostream>
#include<queue>
#include<algorithm>
#include"../Header_Files/TreeNode.h"
using namespace std;


/*
	H.W :
	1. Level Order Traversal se Tree banana hain.
	2. Post order and Preorder se milke ek unique tree banana hain if possible.
	3. Inorder and Preorder se milke ek unique tree banana hain if possible.

	Points to Remember: Inorder Traversal of a BST will always give you a
	sorted data set.
*/


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

	cout << root->val << ",";
	Preorder(root->left);
	Preorder(root->right);
}

void Inorder(TreeNode<int>*root) {

	if (root == NULL) {
		return;
	}

	Inorder(root->left);
	cout << root->val << ",";
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

// int i = 0;

TreeNode<int>*BuildTreeFromPreAndIn(int *pre, int *in, int s, int e) {

	if (s > e) {
		return NULL;
	}

	static int i = 0;
	TreeNode<int>*root = new TreeNode<int>(pre[i]);

	//Search for this pre[0] in inorder array.
	int index = -1;

	for (int j = s; j <= e; j++) {
		if (in[j] == pre[i]) {
			index = j;
			break;
		}
	}

	i++;

	/*
		All the nodes from 0 to i-1 will be left of pre[0] and all the nodes
		from i+1 to n-1 will right of pre[0] node.
	*/

	root->left = BuildTreeFromPreAndIn(pre, in, s, index - 1);
	root->right = BuildTreeFromPreAndIn(pre, in, index + 1, e);

	return root;
}

vector<vector<int>>ans;

void PrintAllLevelUsingBfs(TreeNode<int>*root) {

	queue<TreeNode<int>*>q;
	vector<int>current;

	q.push(root);
	q.push(NULL);

	while (!q.empty()) {


		TreeNode<int>*f = q.front();
		q.pop();

		if (f == NULL) {

			if (!q.empty()) {
				q.push(NULL);
			}

			ans.push_back(current);
			current.clear();
			cout << endl;

		} else {

			current.push_back(f->val);

			if (f->left != NULL) {
				q.push(f->left);
			}

			if (f->right != NULL) {
				q.push(f->right);
			}

		}
	}

	return;
}

void LeftView(TreeNode<int>*root, int Level, int &PrintedLevel) {

	if (root == NULL) {
		return;
	}

	if (PrintedLevel < Level) {
		cout << root->val << " ";
		PrintedLevel = Level;
	}

	LeftView(root->left, Level + 1, PrintedLevel);
	LeftView(root->right, Level + 1, PrintedLevel);
}

void Rightview(TreeNode<int>*root, int Level, int &PrintedLevel) {

	if (root == NULL) {
		return;
	}

	if (PrintedLevel < Level) {
		cout << root->val << " ";
		PrintedLevel = Level;
	}

	Rightview(root->right, Level + 1, PrintedLevel);
	Rightview(root->left, Level + 1, PrintedLevel);
}

TreeNode<int>*InsertInBst(TreeNode<int>*r, int value) {

	if (r == NULL) {
		r = new TreeNode<int>(value);//Creation of Node through constructor
		return r;
	}

	if (r->val > value) {
		r->left = InsertInBst(r->left, value);
	} else {
		r->right = InsertInBst(r->right, value);
	}

	return r;
}

TreeNode<int>*BuildBst() {

	int x;
	cin >> x;

	if (x == -1) {
		return NULL;
	}

	TreeNode<int>*root = NULL;

	while (x != -1) {
		root = InsertInBst(root, x);
		cin >> x;
	}

	return root;//Complete tree root.
}

bool SearchInBst(TreeNode<int>*root, int target) {

	if (root == NULL) {
		return false;
	}

	if (root->val == target) {
		return true;
	}

	if (root->val < target) {
		return SearchInBst(root->right, target);
	} else {
		return SearchInBst(root->left, target);
	}


}


TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {

	if (root == NULL) {
		return  NULL;
	}

	if (root->val == p->val or root->val == q->val) {
		return root;
	}


	TreeNode<int>*leftlca = lowestCommonAncestor(root->left, p, q);
	TreeNode<int>*rightlca = lowestCommonAncestor(root->right, p, q);

	if (leftlca != NULL and rightlca != NULL) {
		return root;
	}

	if (leftlca == NULL) {
		return rightlca;
	}

	return leftlca;
}


TreeNode<int>* lowestCommonAncestor2(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q) {

	if (root == NULL) {
		return NULL;
	}

	if (root->val > p->val and root->val > q->val) {
		return lowestCommonAncestor2(root->left, p, q);
	}

	if (root->val < p->val and root->val < q->val) {
		return lowestCommonAncestor2(root->right, p, q);
	}


	//Any other Scenario.
	return root;
}

int index = 0;
TreeNode<int>* bstFromPreorder(vector<int>& preorder, int maxi = INT_MAX) {

	if (index >= preorder.size() or preorder[index] > maxi) {
		return NULL;
	}

	TreeNode<int>*root = new TreeNode<int>(preorder[index]);
	index++;

	root->left = bstFromPreorder(preorder, root->val);
	root->right = bstFromPreorder(preorder, maxi);
	return root;
}


bool Isbst(TreeNode<int>*root, long long maxi = LONG_MAX, long long mini = LONG_MIN) {

	if (root == NULL) {
		return true;
	}

	//For checking the Current Node
	bool Op1 = 0;
	if (root->val > mini and root->val < maxi) {
		Op1 = true;
	}

	//For the checking the left subtree
	bool Op2 = Isbst(root->left, root->val, mini);

	//For Checking the right subtree.
	bool Op3 = Isbst(root->right, maxi, root->val);


	if (Op1 == 1 and Op2 == 1 and Op3 == 1) {
		return true;
	} else {
		return false;
	}

}

void leftview2(TreeNode<int>* root) {
	queue<TreeNode<int>*> q;

	cout << root -> val << " ";
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		TreeNode<int>* f = q.front();
		q.pop();

		if (f == NULL) {

			if (!q.empty()) {
				q.push(NULL);
				f = q.front();
				cout << f -> val << " ";
			}

		}

		else {

			if (f -> left != NULL) q.push(f -> left);
			if (f -> right != NULL) q.push(f -> right);

		}
	}

}


TreeNode<int> *takeInputLevel() {
	int data;
	cin >> data;

	if (data == -1) {
		return NULL;
	}

	TreeNode<int>* root = new TreeNode<int>(data);
	queue<TreeNode<int>*> q;
	q.push(root);

	while (!q.empty()) {

		TreeNode<int>*curParent = q.front();
		q.pop();

		int leftData;
		cin >> leftData;


		if (leftData != -1) {
			TreeNode<int>* tmp = new TreeNode<int>(leftData);
			curParent->left = tmp;
			q.push(tmp);
		}

		int rightData;
		cin >> rightData;

		if (rightData != -1) {
			TreeNode<int>* tmp = new TreeNode<int>(rightData);
			curParent->right = tmp;
			q.push(tmp);
		}
	}
	return root;
}

TreeNode<int>* buildFromBfs2(vector<int> &arr) {

	if (arr.empty()) {
		return NULL;
	}

	TreeNode<int>*root = new TreeNode<int>(arr[0]);
	queue<TreeNode<int>*> q;
	q.push(root);

	int i = 1;
	while (i < arr.size() and !q.empty()) {
		TreeNode<int>* f = q.front();
		q.pop();

		if (arr[i] != -1) {
			f -> left = new TreeNode<int>(arr[i]);
			q.push(f -> left);
		}
		i++;

		if (i < arr.size() and arr[i] != -1) {
			f -> right = new TreeNode<int>(arr[i]);
			q.push(f -> right);
		}
		i++;

	}

	return root;

}
TreeNode<int>* buildFromBfs(vector<int>&a, int i) {
	if (i >= a.size() or a[i] == -1) {
		return NULL;
	}

	TreeNode<int>* root = new TreeNode<int>(a[i]);

	root -> left = buildFromBfs(a, 2 * i + 1);
	root -> right = buildFromBfs(a, 2 * i + 2);

	return root;
}
