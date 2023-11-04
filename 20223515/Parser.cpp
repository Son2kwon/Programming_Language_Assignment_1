#include"Parser.h"
#include<iostream>
using namespace std;

// <program> → <statements>
void program() {
	statements();
}

// <statements> → <statement> | <statement><semi_colon><statements>
void statements() {
	/*
	look_ahead로 semi_colon있는지 확인
		있으면 <statement><semicolon><statements>
		없으면 <statement>
	*/

	
}