#include<iostream>
using namespace std;

//This is when you only have small case characters.
int main() {

	char ch[1000];
	cin >> ch;
	int freq[26] {0};

	for (int i = 0; ch[i] != '\0'; i++) {
		// int element_index = (int)ch[i];
		// int mapped_index = element_index - 97;
		// freq[mapped_index]++;

		freq[ch[i] - 'a']++;

		// //In case of only digits:
		// freq[ch[i] - '0'];
	}

	for (int i = 0; i < 26; i++) {
		if (freq[i] > 0) {

			//ASCII Value in int is i.
			char Mapped_element = (char)(i + 97);
			cout << Mapped_element << " " << freq[i] << endl;
		}
	}







}