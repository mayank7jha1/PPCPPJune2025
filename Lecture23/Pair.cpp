#include<iostream>
#include"../Header_Files/Pair.h"
using namespace std;


int main() {

	Pair<string, int>p;
	p.first = "Mayank";
	p.second = 1000;

	cout << p.first << " " << p.second << endl;
}