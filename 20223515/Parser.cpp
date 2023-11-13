#include"Parser.h"
#include<iostream>
using namespace std;

// <program> �� <statements>
void program(string* token) {
	statements(token);
}

// <statements> �� <statement> | <statement><semi_colon><statements>
void statements(string* token) {
	/*
	look_ahead�� ���� semi_colon�� �ִ��� Ȯ��
		������ LHS�� <statement><semicolon><statements>
		������ LHS�� <statement>

		<statement>���� ; ���� ����, <statements>���� ; ���� ������ �� ��.
	*/

	if (token->find(';')) {
		int index = token->find(';');	// ���� ó�� ������ ; �� ã��

		string* stmt;

		int i = 0;

		for (; i < index; i++) {
			stmt[i] = token[i];	// stmt�� ; ���� ���ڿ����� �־���
		}

		string* stmts;
		int j = 0;

		while (token[i] != "\0") {
			stmts[j] = token[i];	// stmts�� ; ���� ���ڿ����� �־���
		}

		statement(stmt);

		statements(stmts);
	}

	else {
		statement(token);
	}
}

// <statement> �� <ident><assignment_op><expression>
void statement(string* token) {
	ident(token[0]);	// ù��° string�� ident��
	expression(token + 2);	// 2��° string ���ʹ� expression����
}

void ident(string token) {

}

// <expression> �� <term><term_tail>
void expression(string* token) {
	term(token);
	term_tail(token);
}

// <term> �� <factor> <factor_tail>
void term(string* token) {
	factor(token);
	factor_tail(token);
}

// <term_tail> �� <add_op><term><term_tail> | ��
void term_tail(string* token) {

}

// <factor> �� <left_paren><expression><right_paren> | <ident> | <const>
void factor(string* token) {
	if (token[0] == "(") {
		left_paren();
		expression();
		right_paren();
	}

	else if (true) {
		ident();
	}

	else {
		constant();
	}
}

// <factor_tail> �� <mult_op><factor><factor_tail> | ��
void factor_tail(string* token) {
	if (token[0] == "*") {
		mult_operator();
		factor();
		factor_tail();
	}
}