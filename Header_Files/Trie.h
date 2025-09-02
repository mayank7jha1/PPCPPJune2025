#include<iostream>
#include<unordered_map>
#include"../Header_Files/TrieNode.h"
using namespace std;

class Trie {
private:
	TrieNode* root;
	int number = 0;
public:
	Trie() {
		root = new TrieNode('\0');
	}

	//Everything is going to happen in length of string/word.
	void insert(string &str) {
		TrieNode* temp = root;

		//Step 1: Iterate over the current string.
		for (char ch : str) {

			if (temp->childMap.find(ch) == temp->childMap.end()) {
				/*
					This character is not present as a child of the current
					node.
					I need to create a new node here and insert the data s[i]
					in it.
				*/

				TrieNode* n = new TrieNode(ch);
				temp->childMap[ch] = n;
			}

			temp = temp->childMap[ch];
			temp->freq++;

		}

		temp->terminal = true;
		number++;

	}

	bool search(string &str) {
		TrieNode* temp = root;
		for (char ch : str) {

			if (temp->childMap.count(ch) == 0) {
				return false;
			}

			temp = temp->childMap[ch];
		}

		if (temp->terminal == 1) {
			return true;
		} else {
			return false;
		}
	}

	string shortestUniquePrefix(string &str) {

		TrieNode * temp = root;
		string ans = "";
		for (auto ch : str) {
			ans += ch;
			temp = temp->childMap[ch];

			if (temp->freq == 1) {
				return ans;
			}
		}

		return "";
	}

	string LongestCommonPrefix(string &str) {

		cout << number << endl;
		TrieNode *temp = root;
		string ans = "";
		for (auto ch : str) {
			temp = temp->childMap[ch];
			if (temp->freq != number) {
				break;
			}

			ans += ch;
		}
		return ans;
	}



};



