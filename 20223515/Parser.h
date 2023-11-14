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

void program(vector<string>&);
void statements(vector<string>&);
void statement(string&);
void expression(string&);
void term_tail(string&);
void term(string&);
void factor_tail(string&);
void factor(string&);
void constant(string&);
void ident(string&);

void assignment_op(string&);
void add_operator(string&);
void mult_operator(string&);
void left_paren(string&);
void right_paren(string&);