#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"Parser.h"
using namespace std;

int main(int argc, char* argv[]) {
	ifstream f;
	f.open((argv[1]));
	string* token;
	int index = 0;

	if (f.is_open()) {
		while (!f.eof()) {	// ���Ͽ� �ִ� ��� ������ �о� token�� �����Ϸ� ��.
			string in; f >> token[index];	// txt���Ͽ��� �ܾ �о� token�� ����.
			index++;
		}

		program(token);	// ������ program

		f.close();
	}
	else cout << "Fail to open file" << endl;
}