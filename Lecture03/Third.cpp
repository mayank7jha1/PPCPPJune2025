#include<iostream>
using namespace std;


int main() {

	int w;
	cin >> w;

	/*
		if,else

		if(Iske ander jo likha hain vo sach hain toh){

			inke ander jo likha hain vo kaam karo
		}else{
			iske ander jo likha hai vo kaam karo.
		}

		else : Varna

		== : Is a relational operator it compares right with left and gives true/false as a resultant.
	*/

	if (w == 2) {
		cout << "NO" << endl;
	} else {
		if ((w % 2) == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	// if (w == 2) {
	// 	cout << "NO" << endl;
	// 	return 0;
	// }

	// if ((w % 2) == 0) {
	// 	cout << "YES" << endl;
	// } else {
	// 	cout << "NO" << endl;
	// }


}







