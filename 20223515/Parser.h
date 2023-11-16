#include<iostream>
#include<vector>
#include"lexical_analyzer.h"
using namespace std;

/*
* Grammars

<program> → <statements>
<statements> → <statement> | <statement><semi_colon><statements>
<statement> → <ident><assignment_op><expression>
<expression> → <term><term_tail>
<term_tail> → <add_op><term><term_tail> | ε
<term> → <factor> <factor_tail>
<factor_tail> → <mult_op><factor><factor_tail> | ε
<factor> → <left_paren><expression><right_paren> | <ident> | <const>
<const> → any decimal numbers
<ident> → any names conforming to C identifier rules
<assignment_op> → :=
<semi_colon> → ;
<add_operator> → + | -
<mult_operator> → * | /
<left_paren> → (
<right_paren> → )

*/

typedef struct data {
	string name;
	int value;
}varData;

class symbol_table {	// <ident>의 현재값을 저장하기 위한 symbol table, sentences 단위
public:
	vector<varData> datum;

	bool isThere(const string& target) {	// identifier가 기존에 있던 것인지 확인.
		for (varData& cur : datum) {
			if (cur.name == target) {
				return true;
			}
		}

		return false;
	}
};

void program(vector<sentence>& sentences);
void statements(vector<sentence>& sentences);
void statement(sentence&);
void expression(sentence&);
void term_tail(sentence&);
void term(sentence&);
void factor_tail(sentence&);
void factor(sentence&);
void constant(sentence&);
void ident(sentence&);

void assignment_op(sentence&);
void add_operator(sentence&);
void mult_operator(sentence&);
void left_paren(sentence&);
void right_paren(sentence&);