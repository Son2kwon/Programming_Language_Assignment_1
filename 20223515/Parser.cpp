#include"Parser.h"
#include<iostream>
using namespace std;

// <program> → <statements>
void program(string* token) {
	statements(token);
}

// <statements> → <statement> | <statement><semi_colon><statements>
void statements(string* token) {
	/*
	look_ahead를 통해 semi_colon이 있는지 확인
		있으면 LHS는 <statement><semicolon><statements>
		없으면 LHS는 <statement>

		<statement>에는 ; 이전 내용, <statements>에는 ; 다음 내용이 들어갈 것.
	*/

	if (token->find(';')) {
		int index = token->find(';');	// 가장 처음 만나는 ; 를 찾음

		string* stmt;

		int i = 0;

		for (; i < index; i++) {
			stmt[i] = token[i];	// stmt에 ; 이전 문자열들을 넣어줌
		}

		string* stmts;
		int j = 0;

		while (token[i] != "\0") {
			stmts[j] = token[i];	// stmts에 ; 이후 문자열들을 넣어줌
		}

		statement(stmt);

		statements(stmts);
	}

	else {
		statement(token);
	}
}

// <statement> → <ident><assignment_op><expression>
void statement(string* token) {
	ident(token[0]);	// 첫번째 string은 ident로
	expression(token + 2);	// 2번째 string 부터는 expression으로
}

void ident(string token) {

}

// <expression> → <term><term_tail>
void expression(string* token) {
	term(token);
	term_tail(token);
}

// <term> → <factor> <factor_tail>
void term(string* token) {
	factor(token);
	factor_tail(token);
}

// <term_tail> → <add_op><term><term_tail> | ε
void term_tail(string* token) {

}

// <factor> → <left_paren><expression><right_paren> | <ident> | <const>
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

// <factor_tail> → <mult_op><factor><factor_tail> | ε
void factor_tail(string* token) {
	if (token[0] == "*") {
		mult_operator();
		factor();
		factor_tail();
	}
}