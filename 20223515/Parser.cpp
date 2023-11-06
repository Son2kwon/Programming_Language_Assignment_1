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
	look_ahead�� semi_colon�ִ��� Ȯ��
		������ <statement><semicolon><statements>
		������ <statement>
	*/

	
}