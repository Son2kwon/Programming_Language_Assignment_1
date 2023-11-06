#include<iostream>
using namespace std;

/*
* Grammars
* 
<program> 占쏙옙 <statements>
<statements> 占쏙옙 <statement> | <statement><semi_colon><statements>
<statement> 占쏙옙 <ident><assignment_op><expression>
<expression> 占쏙옙 <term><term_tail>
<term_tail> 占쏙옙 <add_op><term><term_tail> | 占쏙옙
<term> 占쏙옙 <factor> <factor_tail>
<factor_tail> 占쏙옙 <mult_op><factor><factor_tail> | 占쏙옙
<factor> 占쏙옙 <left_paren><expression><right_paren> | <ident> | <const>
<const> 占쏙옙 any decimal numbers
<ident> 占쏙옙 any names conforming to C identifier rules
<assignment_op> 占쏙옙 :=
<semi_colon> 占쏙옙 ;
<add_operator> 占쏙옙 + | -
<mult_operator> 占쏙옙 * | /
<left_paren> 占쏙옙 (
<right_paren> 占쏙옙 )

*/

void program(string* token);
void statements(string* token);
void statement();
void expression();
void term_tail();
void term();
void factor_tail();
void factor();
void constant();
void ident();
void assignment_op();
void semi_colon();
void add_operator();
void mult_operator();
void left_paren();
void right_paren();