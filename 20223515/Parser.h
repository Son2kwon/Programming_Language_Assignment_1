#include<iostream>
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

void program(string* token);
void statements(string* token);
void statement(string* token);
void expression(string* token);
void term_tail(string* token);
void term(string* token);
void factor_tail(string* token);
void factor(string* token);
void constant();
void ident(string token);

void add_operator();
void mult_operator();
void left_paren();
void right_paren();