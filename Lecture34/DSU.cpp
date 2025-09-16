#include<iostream>
using namespace std;


class DSU {
public:
	vector<int>superparent;
	vector<int>parent;
	vector<int>rank;
	int TotalComponents;

	//Constructor
	DSU(int n) {
		superparent.resize(n, -1);
		rank.resize(n, 1);
		TotalComponents = n;//Intial Number of Components.
	}

	//n computation in case of parent vector.
	//This function tells you the superparent of a node.
	// int FindS(int node) {
	// 	if (parent[node] == -1) {
	// 		return node;
	// 	}
	// 	return FindS(parent[node]);
	// }

	//Dp and storing the superparent of a node and hence
	//computation to find the superparent reduces to 1.

	int FindS(int node) {
		if (superparent[node] == -1) {
			return node;
		}
		//Path Compression.
		return superparent[node] = FindS(superparent[node]);
	}


	void UnionS(int x, int y) {

		//Union By rank:
		int S1 = FindS(x);
		int S2 = FindS(y);

		if (S1 != S2) {
			//Union by rank:

			if (rank[S1] < rank[S2]) {
				superparent[S1] = S2;
				rank[S2] += rank[S1];
			} else {
				superparent[S2] = S1;
				rank[S1] += S2;
			}

			TotalComponents--;
		}

	}
};


int main() {



}