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
	look_ahead를 통햐 semi_colon이 있는지 확인
		있으면 LHS는 <statement><semicolon><statements>
		없으면 LHS는 <statement>
	*/

	
}