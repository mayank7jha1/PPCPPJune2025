#include<iostream>
#include<unordered_map>
using namespace std;

class TrieNode {
public:
	char ch;
	bool terminal;
	unordered_map<char, TrieNode*>childMap;
	int freq;

	//Default Constructor
	TrieNode() {

	}

	//Parameterised Constructor
	TrieNode(char ch) {
		this->ch = ch;
		this->terminal = false;
		freq = 0;
	}

};


