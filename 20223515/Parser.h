#include<iostream>
#include<vector>
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

class sent {	// 한 문장에 대해 정보를 저장하는 class
public:
	int ID;
	int CONST;
	int OP;
	string sentence;

	sent(string sentence) {
		this->sentence = sentence;
		this->ID = 0;
		this->CONST = 0;
		this->OP = 0;
	}
};

void program(vector<string>&);
void statements(vector<string>&);
void statement(sent&);
void expression(sent&);
void term_tail(sent&);
void term(sent&);
void factor_tail(sent&);
void factor(sent&);
void constant(sent&);
void ident(sent&);

void assignment_op(sent&);
void add_operator(sent&);
void mult_operator(sent&);
void left_paren(sent&);
void right_paren(sent&);