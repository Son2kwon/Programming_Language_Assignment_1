#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include"Parser.h"
using namespace std;

int main(int argc, char* argv[]) {
	ifstream f;
	f.open(argv[1]);
	vector<string> sentences;	// 문장들을 저장하는 sentences vector (신세계 shit...)
	string line;

	if (f.is_open()) {
		while (getline(f, line)) {	// 1문장씩 읽어오면서 sentence에 저장
			size_t temp_index = line.find(';');

			if (temp_index != std::string::npos) {	// 만약 문장 중간에 ; 가 있으면 2개의 문장으로 분리 후 저장
				string line1 = line.substr(0, temp_index) + ';';	// ; 이전 문장
				string line2 = line.substr(temp_index + 1);	// ; 이후 문장

				sentences.push_back(line1);	// 우선 ; 이전 문장을 저장

				if (!line2.empty()) {	// 만약 ; 이후 문장이 비어있지 않다면 저장
					sentences.push_back(line2);
				}
			}
			
			else {									// 문장 중간에 ; 가 없으면 그냥 저장
				sentences.push_back(line);
			}
		}

		program(sentences);

		f.close();
	}

	else cout << "Fail to open file" << endl;
}