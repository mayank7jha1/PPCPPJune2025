#include<iostream>
#include<map>
#include<list>
#include<utility>
#include<algorithm>
using namespace std;


//Undirected/Directed Unweighted Graph.
template<typename T>
class Graph {
private:
	map<T, list<T>>mp;//Adj. List
public:

	void addedge(T x, T y, int direction) {
		mp[x].push_back(y);

		if (direction == 0) {
			//This is an undirected egde.
			mp[y].push_back(x);
		}
	}

	void Print() {
		//Print the Adj List.
		for (pair<int, list<int>> info : mp) {
			int node = info.first;
			list<int>nbr_info = info.second;
			cout << node << " : ";
			for (int nbrs : nbr_info) {
				cout << nbrs << " ";
			}
			cout << endl;
		}
	}

};


int main() {

	int n, m;
	cin >> n >> m;

	int direction = 0;

	Graph<int>gr;
	for (int i = 0; i < m; i++) {
		int sp, ep;
		cin >> sp >> ep;
		gr.addedge(sp, ep, direction);
	}

	gr.Print();
}