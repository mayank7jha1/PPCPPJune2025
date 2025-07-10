#include<iostream>
using namespace std;


int main() {

	char ch[1000];
	cin >> ch;
	int freq[256] {0};

	for (int i = 0; ch[i] != '\0'; i++) {
		// int element_index = (int)ch[i];
		// freq[element_index]++;
		freq[ch[i]]++;
	}

	for (int i = 0; i < 256; i++) {
		if (freq[i] > 0) {
			//ASCII Value in int is i.
			char original_element = (char)i;
			cout << original_element << " " << freq[i] << endl;
		}
	}







}