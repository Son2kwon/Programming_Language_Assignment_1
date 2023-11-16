#include"lexical_analyzer.h"
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;

int next_token;
string token_string;

// string이 숫자인지 판단하는 함수
bool isNumber(const std::string& str);

void lexical(const string token) {
	if (token == "(") {
		next_token = LEFT_PAREN;
	}

	else if (token == ")") {
		next_token = RIGHT_PAREN;
	}

	else if (token == ":=") {
		next_token = ASSIGN_OP;
	}

	else if (token == "+") {
		next_token = ADD_OP;
	}

	else if (token == "-") {
		next_token = SUB_OP;
	}

	else if (token == "*") {
		next_token = MULT_OP;
	}

	else if (token == "/") {
		next_token = DIV_OP;
	}

	else if (token == ":=") {
		next_token = ASSIGN_OP;
	}

	else if (isNumber(token)) {
		next_token = CONSTANT;
	}

	else {
		next_token = IDENT;
	}

	token_string = token;

}

// 숫자인지 판단하는 함수
bool isNumber(const std::string& str) {
	try {
		size_t pos;
		std::stoi(str, &pos);
		return pos == str.length();  // If pos is equal to the string length, the entire string was converted
	}
	catch (const std::invalid_argument& e) {
		return false;  // Conversion failed
	}
	catch (const std::out_of_range& e) {
		return false;  // Value is out of the range of representable values for the int type
	}
}