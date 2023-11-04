#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"Parser.h"

int main(int args, char* argv[]) {
	ifstream f(argv[1]);
	string line;
	string* token;

	if (f.is_open()) {
		while (getline(f, line)) {
			stringstream ss(line);
			int index = 0;

			cout << line << endl;
			
			while (ss >> token[index]) {
				
			}
		}
	}
	else cout << "Fail to open file" << endl;
}