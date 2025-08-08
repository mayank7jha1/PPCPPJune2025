#include<iostream>
#include<vector>
using namespace std;


int main() {

	int n;
	cin >> n;

	vector<vector<string>>ans;

	//ans is a vector whose every index is a vector<string>

	vector<string>v1;//One way to put queen
	vector<string>v2;//One way to put queen
	vector<string>v3;//One way to put queen

	for (int i = 0; i < n; i++) {
		string s = "";
		for (int j = 0; j < n; j++) {
			s.push_back('.');
		}
		// s = s + "....";
		v1.push_back(s);
		v2.push_back(s);
		v3.push_back(s);
	}

	ans.push_back(v1);
	ans.push_back(v2);
	ans.push_back(v3);

	// for (int i = 0; i < n; i++) {
	// 	cout << v1[i] << endl;
	// }

	// cout << "----------------" << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << v2[i] << endl;
	// }
	// cout << "----------------" << endl;
	// for (int i = 0; i < n; i++) {
	// 	cout << v3[i] << endl;
	// }


	for (int i = 0; i < ans.size(); i++) {
		//ans[i]: this is a vector<string>
		for (int j = 0; j < ans[i].size(); j++) {
			//ans[i][j] : this is a string
			cout << ans[i][j] << endl;
		}
		cout << "-------" << endl;
	}


	for (int i = 0; i < ans.size(); i++) {
		//ans[i]: this is a vector<string>
		for (int j = 0; j < ans[i].size(); j++) {
			for (int k = 0; k < ans[i][j].length(); k++) {
				//ans[i][j][k] : It is a character
				cout << ans[i][j][k];
			}
			cout << endl;
		}
		cout << "-------" << endl;
	}


}






