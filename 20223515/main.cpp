#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include"Parser.h"
using namespace std;

int main(int args, char* argv[]) {
	ifstream f(argv[1]);
	string line;
	string* token;

	if (f.is_open()) {
		while (getline(f, line)) {	// txt파일 끝에 닿을 때까지 한 줄 씩 읽어옴
			stringstream ss(line);	// 공백을 기준으로 문자열을 나눔
			int index = 0;

			cout << line << endl;	// 읽어온 문장을 출력
			
			while (ss >> token[index]) index++;	// 그 문장을 token이라는 문자열 배열에 넣어줌

			program(token);
		}
	}
	else cout << "Fail to open file" << endl;
}