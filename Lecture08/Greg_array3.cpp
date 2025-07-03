#include<iostream>
using namespace std;


int main() {

	int n, m, k;
	cin >> n >> m >> k;

	//I have taken array a with size n+1 since
	//I am going everything on this array with 1 based
	//index i.e. I am just always ignonring zero index.

	int a[100001] {0};

	//Be careful while taking input:
	//take input from index 1 to n not 0 to n-1.
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	/*
		I am given m operations and every Operation
		contains three values: l,r,d corresponding to
		the respective operation.


		Q. How do I store these values.
		How  many values are there: m*3.
		it is not possible to create these many variables.

		I can create a l array corresponding to each query
		similary a r array d array.

		that means : When are taking about operation number
		7 : the values can be fetched as l[7],r[7],d[7];


		and to perform 7th operation it means:

		You need to add d[7] to every index of array a
		in range l[7] to r[7].

	*/
	int l[100001] {0}, r[100001] {0}, d[100001] {0};

	int i = 1;
	while (i <= m) {
		cin >> l[i] >> r[i] >> d[i];
		i++;
	}


	//Now take input for query and also solve the query.

	i = 1;
	while (i <= k) {

		int x, y;
		cin >> x >> y;

		//Since I am not storing x and y individually for every
		//query I will be solving every query as soon as
		//I take the input for that query.

		//THat means Currently I am solving query i where i can
		//go from 1 to k values.

		//since I am solving query i this means:
		//You need to perform operation from x to y.

		//This means : first person operation number x, then perfrom
		//operation number x+1, then x+2 . . . .. . .operation
		//number y.

		//to perfrom operation number x it means:
		//add d[x] to array a from index l[x] to r[x] index.

		//I first need to go from operation number x to y.

		for (int z = x; z <= y; z++) {

			//Current Operation ko perform karne ka
			//matlab is: l[z] se lekar r[z] tak d[z] ko add karo.

			for (int o = l[z]; o <= r[z]; o++) {
				a[o] += d[z];
			}


		}


		i++;
	}

	//While Printing also be careful you need to print
	//the array according to 1 based indexing.
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}













}