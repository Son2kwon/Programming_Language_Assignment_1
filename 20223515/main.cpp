#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"Parser.h"

int main(int args, char* argv[]) {
	ifstream f(argv[1]);
	string* token = NULL;
	int index = 0;

	if (f.is_open()) {
		while (!f.eof()) {
			string in; f >> in;
			token[index] = in;

			if (in[0] == ';') {
				program(token);
			}
		}

		f.close();
	}
	else cout << "Fail to open file" << endl;
}