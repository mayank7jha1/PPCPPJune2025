#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
const int N = 1e5 + 4;
vector<int>gr[N];//Assuming that all the vertices of the graph will be integers only. (Adjacency List)


/*
	Every index of gr[i] will contain a vector.
	gr[i] represents a node and every gr[i] will have a vector containing the
	neighbours of gr[i].

*/


void bfs(int scr, int n, int &shl) {

	vector<int>distance(n + 1, INT_MAX);

	queue<int>q;
	q.push(scr);
	distance[scr] = 0;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (auto nbr : gr[node]) {

			if (distance[nbr] == INT_MAX) {
				q.push(nbr);
				distance[nbr] = distance[node] + 1;
			} else if (distance[nbr] >= distance[node]) {
				//This is a backedge and this nbr cannot be the parent of node.
				//Cycle Length:
				int cl = distance[nbr] + distance[node] + 1;
				shl = min(shl, cl);
			}
		}
	}
}




int main() {

	int n, m;
	cin >> n >> m;

	//This graph will only contain integer values.
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	//n : number of nodes in the graph.
	int Shortest_Cycle_Length = n + 1;


	//Logic: Apply bfs from each and every node of the graph.
	for (int i = 1; i <= n; i++) {
		bfs(i, n, Shortest_Cycle_Length);
	}

	if (Shortest_Cycle_Length == n + 1) {
		cout << "No Cycle " << endl;
	} else {
		cout << Shortest_Cycle_Length << endl;
	}


}