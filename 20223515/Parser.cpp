#include"Parser.h"
#include<iostream>
using namespace std;

// <program> �� <statements>
void program() {
	statements();
}

// <statements> �� <statement> | <statement><semi_colon><statements>
void statements() {
	/*
	look_ahead�� semi_colon�ִ��� Ȯ��
		������ <statement><semicolon><statements>
		������ <statement>
	*/

	
}