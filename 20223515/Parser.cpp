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

// <program> �� <statements>
void program(vector<string>& sentences) {
	statements(sentences);
}

// <statements> �� <statement> | <statement><semi_colon><statements>
void statements(vector<string>& sentences) {
	/*
	look_ahead�� ���� ù ���忡 semi_colon�� �ִ��� Ȯ��
		������ LHS�� <statement><semicolon><statements>
		������ LHS�� <statement>

		<statement>���� ù ����
		<statements>���� �̿��� ����
	*/

	if (sentences[0].find(';')) {
		int index_semi = sentences[0].find(';');
		string sentence = sentences[0].substr(0, index_semi - 1);	// ù ; ���� ������ statement��

		sentences.erase(sentences.begin());	// ù ���� �����ؼ� ���� ������ sentences vector�� ����

		statement(sentence);

		if(!sentences.empty()) statements(sentences);
	}

	else {
		statement(sentences[0]);
	}
}

// <statement> �� <ident><assignment_op><expression>
void statement(string& sentence) {
	/*
	
	*/

	//string identifier, expr;
	//
	//int assign_index = sentence.find(":=");

	//identifier = sentence.substr(0, assign_index - 1);	// := ���� string
	//expr = sentence.substr(assign_index + 3);	// := ���� string

	//ident(identifier);
	//expression(expr);

	ident(sentence);
	assignment_op(sentence);
	expression(sentence);

}

// <ident> �� any names conforming to C identifier rules
void ident(string& sentence) {
	int blank = sentence.find(' ');

	string identifier = sentence.substr(0, blank);
	sentence = sentence.substr(blank + 1);


	cout << "identifier: " << identifier << endl;
}

void assignment_op(string& sentence) {
	int blank = sentence.find(' ');

	string assign_op = sentence.substr(0, blank);
	sentence = sentence.substr(blank + 1);

	cout << "assignment operator: " << assign_op << endl;
}

// <expression> �� <term><term_tail>
void expression(string& sentence) {
	/*
	
	*/
	term(sentence);
	term_tail(sentence);
}

// <term> �� <factor> <factor_tail>
void term(string& sentence) {
	/*
	
	*/

	factor(sentence);
	factor_tail(sentence);
}
	

// <term_tail> �� <add_op><term><term_tail> | ��
void term_tail(string& sentence) {
	/*
	
	*/
	string add = "+";

	if (sentence.compare(0, add.length(), add) == 0) {
		add_operator(sentence);
		term(sentence);
		term_tail(sentence);
	}

	else {
		return;
	}
}

// <factor> �� <left_paren><expression><right_paren> | <ident> | <const>
void factor(string& sentence) {
	string left = "(";

	if (sentence.compare(0, left.length(), left) == 0) {	// �ް�ȣ�� �ִ� ���
		left_paren(sentence);
		expression(sentence);
		right_paren(sentence);
	}

	else if (isNumber(sentence)) {	// constant�� �ִ� ���
		constant(sentence);
	}

	else {			// identifier�� �ִ� ���
		ident(sentence);
	}
}

// <factor_tail> �� <mult_op><factor><factor_tail> | ��
void factor_tail(string& sentence) {
	string mul = "*";

	if (sentence.compare(0, mul.length(), mul) == 0) {
		mult_operator(sentence);
		factor(sentence);
		factor_tail(sentence);
	}

	else {
		return;
	}
}

void add_operator(string& sentence) {
	int add = sentence.find('+') + 1;

	string add_op = sentence.substr(0, add);
	sentence = sentence.substr(add + 1);
	
	cout << "add operator " << add_op << endl;
}

void mult_operator(string& sentence) {
	int mul = sentence.find('*') + 1;

	string mul_op = sentence.substr(0, mul);
	sentence = sentence.substr(mul + 1);

	cout << "mul operator " << mul_op << endl;
}

void left_paren(string& sentence) {
	int left = sentence.find('(');

	string left_paren = sentence.substr(0, left);
	sentence = sentence.substr(left + 1);

	cout << "mul operator " << left_paren << endl;
}

void right_paren(string& sentence) {
	int right = sentence.find('(');

	string right_paren = sentence.substr(0, right);
	sentence = sentence.substr(right + 1);

	cout << "mul operator " << right_paren << endl;
}

void constant(string& sentence) {
	cout << "Constant: " << sentence << endl;
	sentence = "\0";
}