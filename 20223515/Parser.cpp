#include"Parser.h"
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

extern int next_token;
extern string token_string;
symbol_table table;


// 결과를 출력하는 함수
void printResult(sentence& sentence) {
	cout << "ID: " << sentence.ID << "; ";
	cout << "CONST: " << sentence.CONST << "; ";
	cout << "OP: " << sentence.OP << ";" << endl;
}

// <program> → <statements>
void program(vector<sentence>& sentences) {
	statements(sentences);
}

// <statements> → <statement> | <statement><semi_colon><statements>
void statements(vector<string>& sentences) {
	/*

	*/


}

// <statement> → <ident><assignment_op><expression>
void statement(sentence& const sentence) {
	/*

	*/

	cout << sentence.sentence << endl;

	ident(sentence);
	assignment_op(sentence);
	expression(sentence);

	printResult(sentence);
}

// <ident> → any names conforming to C identifier rules
void ident(sentence& sentence) {
	int blank = sentence.sentence.find(' ');

	string identifier = sentence.sentence.substr(0, blank);
	sentence.sentence = sentence.sentence.substr(blank + 1);
	sentence.ID++;

	if (sentence.sentence.find(":=") == 0) {		// 정의하는 부분이라면
		if (!table.isThere(identifier)) {	// 기존에 없다면 저장
			varData data; data.name = identifier; data.value = 0;
			table.datum.push_back(data);
		}									// 있으면 오류 x
	}

	else {									// 정의하는 부분이 아니라면
		if (table.isThere(identifier)) {	// 기존에 없다면 오류
			sentence.error = true;
			varData data; data.name = identifier; data.value = NULL;
		}

		else {								// 있다면 오류 x

		}
	}

}

void assignment_op(sentence& sentence) {
	int blank = sentence.sentence.find(' ');

	string assign_op = sentence.sentence.substr(0, blank);
	sentence.sentence = sentence.sentence.substr(blank + 1);
}

// <expression> → <term><term_tail>
void expression(sentence& sentence) {
	/*

	*/
	term(sentence);
	term_tail(sentence);
}

// <term> → <factor> <factor_tail>
void term(sentence& sentence) {
	/*

	*/

	factor(sentence);
	factor_tail(sentence);
}


// <term_tail> → <add_op><term><term_tail> | ε
void term_tail(sentence& sentence) {
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
void factor(sentence& sentence) {
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
void factor_tail(sentence& sentence) {
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

void add_operator(sentence& sentence) {
	int add = sentence.sentence.find('+') + 1;

	string add_op = sentence.sentence.substr(0, add);
	sentence.sentence = sentence.sentence.substr(add + 1);

	sentence.OP++;
}

void mult_operator(sentence& sentence) {
	int mul = sentence.sentence.find('*') + 1;

	string mul_op = sentence.sentence.substr(0, mul);
	sentence.sentence = sentence.sentence.substr(mul + 1);

	sentence.OP++;
}

void left_paren(sentence& sentence) {
	int left = sentence.sentence.find('(');

	string left_paren = sentence.sentence.substr(0, left);
	sentence.sentence = sentence.sentence.substr(left + 1);
}

void right_paren(sentence& sentence) {
	int right = sentence.sentence.find('(');

	string right_paren = sentence.sentence.substr(0, right);
	sentence.sentence = sentence.sentence.substr(right + 1);
}

void constant(sentence& sentence) {
	sentence.sentence = "\0";
	sentence.CONST++;
}