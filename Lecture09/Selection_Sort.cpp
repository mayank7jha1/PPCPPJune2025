#include<iostream>
using namespace std;


int main() {

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}



	//Computations:
	//Number of tasks: 0 ---- n-2 i.e. n-1 tasks
	//that means for the array to be sorted you need
	//to find out n-1 times the smallest element.

	//For every smallest element that you need to find:
	// n times kuch kaam kar rahe ho.

	// n-1 * n ~~ (n*n)

	int count = 0;

	for (int task = 0; task < n - 1; task++) {

		//This stores the index.
		int mini = task;
		count++;

		for (int j = task + 1; j < n; j++) {
			count++;
			if (a[mini] > a[j]) {
				count++;
				mini = j;
			}
		}

		//For the current task you have
		//found the minimum element.
		count++;
		int temp = a[mini];
		a[mini] = a[task];
		a[task] = temp;

	}

	cout << count << endl;


	// for (int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }





}