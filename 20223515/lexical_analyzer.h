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

// 한 문장에 대해 정보를 저장하는 class
class sentence {					
public:
	int ID;							// 그 문장의 identifier 개수
	int CONST;						// 그 문장의 constant 개수
	int OP;							// 그 문장의 operator 개수
	vector<string> lexemes;			// 문장의 lexemes

	sentence(string sentence) {	// constructor
		this->lexemes = tokenize(sentence);
		this->ID = 0;
		this->CONST = 0;
		this->OP = 0;
	}

private:
	vector<string> tokenize(string sentence) {						// tokenize하는 함수
		stringstream ss(sentence);
		string token;												// lexeme을 저장하기 위한 임시 변수
		
		vector<string> result_lexemes;
		while (ss >> token) result_lexemes.push_back(token);		// lexeme 저장

		return result_lexemes;
	}

	/*
	발생할 수 있는 오류

	1. 정의되지 않은 변수의 사용					-> 수정 불가능
	2. 중복 연산자(+, *)							-> 수정 가능
	3. identifier 뒤에 identifier가 나오는 경우.	-> 수정 불가능
	4. keyword를 사용할 경우						-> 수정 불가능
	*/
};

void lexical(const string token);