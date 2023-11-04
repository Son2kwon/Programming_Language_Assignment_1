#include<iostream>
#include<fstream>
#include<string>
#include"Parser.h"

int main(int args, char* argv[]) {
	ifstream f(argv[1]);
	string line;

	if (f.is_open()) {
		while (getline(f, line)) {

		}
	}
	else cout << "Fail to open file" << endl;
}