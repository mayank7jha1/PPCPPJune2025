#include<iostream>
using namespace std;


int main() {


	int n, m, k;
	cin >> n >> m >> k;

	int a[n + 1] {0};

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	//We have m operations and we need to
	//store those m operations.


	//What do we need to store in those m operations?

	//Every Operation has l,r,d
	//so we m times l,r,d respective to every operation.


	int l[m + 1] {0}, r[m + 1] {0}, d[m + 1] {0};

	//Mere liye ek operation ka matlab hain:
	//l[i] se lekar r[i] index tak a array me d[i] ko add
	//kardo.


	for (int i = 0; i < m; i++) {
		//We are taking input for ith operation.
		cin >> l[i] >> r[i] >> d[i];
	}


	//We hav some number of queries:

	int i = 1;
	while (i <= q) {

		int x, y;
		cin >> x >> y;

		//Current query is [x,y]:
		//iska matlab ye hain ki aapko x as a value se
		// lekar y as a value tak operation perform karna hain.
		//aapko operation number x se lekar i.e. {l[x],r[x],d[x]} isse
		//lekar operation number y tak perfrom karna hain.

		//{l[y],r[y],d[y]};


		for (int op = x; op <= y; op++) {
			//For my current operation:

			//Current Operation number is op:






		}



		i++;
	}









}












