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
		while (!f.eof()) {	// 파일에 있는 모든 문장을 읽어 token에 저장하려 함.
			string in; f >> token[index];	// txt파일에서 단어를 읽어 token에 저장.
			index++;
		}

		program(token);	// 시작은 program

		f.close();
	}
	else cout << "Fail to open file" << endl;
}