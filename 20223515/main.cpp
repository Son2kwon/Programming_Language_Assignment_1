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
	vector<string> sentences;	// ������� �����ϴ� sentences vector (�ż��� shit...)
	string line;

	if (f.is_open()) {
		while (getline(f, line)) {	// 1���徿 �о���鼭 sentence�� ����
			size_t temp_index = line.find(';');

			if (temp_index != std::string::npos) {	// ���� ���� �߰��� ; �� ������ 2���� �������� �и� �� ����
				string line1 = line.substr(0, temp_index) + ';';	// ; ���� ����
				string line2 = line.substr(temp_index + 1);	// ; ���� ����

				sentences.push_back(line1);	// �켱 ; ���� ������ ����

				if (!line2.empty()) {	// ���� ; ���� ������ ������� �ʴٸ� ����
					sentences.push_back(line2);
				}
			}
			
			else {									// ���� �߰��� ; �� ������ �׳� ����
				sentences.push_back(line);
			}
		}

		program(sentences);

		f.close();
	}

	else cout << "Fail to open file" << endl;
}