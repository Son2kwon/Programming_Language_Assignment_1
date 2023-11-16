#pragma once
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

/* Character classes */
#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99

/* Token codes */
#define CONSTANT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

// �� ���忡 ���� ������ �����ϴ� class
class sentence {					
public:
	int ID;							// �� ������ identifier ����
	int CONST;						// �� ������ constant ����
	int OP;							// �� ������ operator ����
	vector<string> lexemes;			// ������ lexemes

	sentence(string sentence) {	// constructor
		this->lexemes = tokenize(sentence);
		this->ID = 0;
		this->CONST = 0;
		this->OP = 0;
	}

private:
	vector<string> tokenize(string sentence) {						// tokenize�ϴ� �Լ�
		stringstream ss(sentence);
		string token;												// lexeme�� �����ϱ� ���� �ӽ� ����
		
		vector<string> result_lexemes;
		while (ss >> token) result_lexemes.push_back(token);		// lexeme ����

		return result_lexemes;
	}

	/*
	�߻��� �� �ִ� ����

	1. ���ǵ��� ���� ������ ���					-> ���� �Ұ���
	2. �ߺ� ������(+, *)							-> ���� ����
	3. identifier �ڿ� identifier�� ������ ���.	-> ���� �Ұ���
	4. keyword�� ����� ���						-> ���� �Ұ���
	*/
};

void lexical(const string token);