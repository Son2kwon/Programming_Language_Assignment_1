#include"Parser.h"
#include<iostream>
#include<string>
#include<cmath>
using namespace std;


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

// <program> → <statements>
void program(vector<string>& sentences) {
	statements(sentences);
}

// <statements> → <statement> | <statement><semi_colon><statements>
void statements(vector<string>& sentences) {
	/*
	look_ahead를 통해 첫 문장에 semi_colon이 있는지 확인
		있으면 LHS는 <statement><semicolon><statements>
		없으면 LHS는 <statement>

		<statement>에는 첫 문장
		<statements>에는 이외의 문장
	*/

	if (sentences[0].find(';')) {
		int index_semi = sentences[0].find(';');
		sent sentence(sentences[0].substr(0, index_semi - 1));	// 첫 ; 이전 문장은 statement로

		sentences.erase(sentences.begin());	// 첫 문장 제거해서 남은 문장을 sentences vector에 저장

		statement(sentence);

		if(!sentences.empty()) statements(sentences);
	}

	else {
		sent sentence(sentences[0]);

		statement(sentence);
	}
}

// <statement> → <ident><assignment_op><expression>
void statement(sent& sentence) {
	/*
	
	*/

	cout << sentence.sentence << endl;
	ident(sentence);
	assignment_op(sentence);
	expression(sentence);

	cout << "ID: " << sentence.ID << "; ";
	cout << "CONST: " << sentence.CONST << "; ";
	cout << "OP: " << sentence.OP << ";" << endl;

}

// <ident> → any names conforming to C identifier rules
void ident(sent& sentence) {
	int blank = sentence.sentence.find(' ');

	string identifier = sentence.sentence.substr(0, blank);
	sentence.sentence = sentence.sentence.substr(blank + 1);
	sentence.ID++;

	//cout << "identifier: " << identifier << endl;
}

void assignment_op(sent& sentence) {
	int blank = sentence.sentence.find(' ');

	string assign_op = sentence.sentence.substr(0, blank);
	sentence.sentence = sentence.sentence.substr(blank + 1);

	// cout << "assignment operator: " << assign_op << endl;
}

// <expression> → <term><term_tail>
void expression(sent& sentence) {
	/*
	
	*/
	term(sentence);
	term_tail(sentence);
}

// <term> → <factor> <factor_tail>
void term(sent& sentence) {
	/*
	
	*/

	factor(sentence);
	factor_tail(sentence);
}
	

// <term_tail> → <add_op><term><term_tail> | ε
void term_tail(sent& sentence) {
	/*
	
	*/
	string add = "+";

	if (sentence.sentence.compare(0, add.length(), add) == 0) {
		add_operator(sentence);
		term(sentence);
		term_tail(sentence);
	}

	else {
		return;
	}
}

// <factor> → <left_paren><expression><right_paren> | <ident> | <const>
void factor(sent& sentence) {
	string left = "(";

	if (sentence.sentence.compare(0, left.length(), left) == 0) {	// 왼괄호가 있는 경우
		left_paren(sentence);
		expression(sentence);
		right_paren(sentence);
	}

	else if (isNumber(sentence.sentence)) {	// constant가 있는 경우
		constant(sentence);
	}

	else {			// identifier가 있는 경우
		ident(sentence);
	}
}

// <factor_tail> → <mult_op><factor><factor_tail> | ε
void factor_tail(sent& sentence) {
	string mul = "*";

	if (sentence.sentence.compare(0, mul.length(), mul) == 0) {
		mult_operator(sentence);
		factor(sentence);
		factor_tail(sentence);
	}

	else {
		return;
	}
}

void add_operator(sent& sentence) {
	int add = sentence.sentence.find('+') + 1;

	string add_op = sentence.sentence.substr(0, add);
	sentence.sentence = sentence.sentence.substr(add + 1);
	
	// cout << "add operator " << add_op << endl;
	sentence.OP++;
}

void mult_operator(sent& sentence) {
	int mul = sentence.sentence.find('*') + 1;

	string mul_op = sentence.sentence.substr(0, mul);
	sentence.sentence = sentence.sentence.substr(mul + 1);

	// cout << "mul operator " << mul_op << endl;
	sentence.OP++;
}

void left_paren(sent& sentence) {
	int left = sentence.sentence.find('(');

	string left_paren = sentence.sentence.substr(0, left);
	sentence.sentence = sentence.sentence.substr(left + 1);

	// cout << "mul operator " << left_paren << endl;
}

void right_paren(sent& sentence) {
	int right = sentence.sentence.find('(');

	string right_paren = sentence.sentence.substr(0, right);
	sentence.sentence = sentence.sentence.substr(right + 1);

	// cout << "mul operator " << right_paren << endl;
}

void constant(sent& sentence) {
	// cout << "Constant: " << sentence.sentence << endl;
	sentence.sentence = "\0";
	sentence.CONST++;
}