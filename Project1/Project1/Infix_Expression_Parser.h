#pragma once
#ifndef INFIX_EXPRESION_PARSER_H_
#define INFIX_EXPRESION_PARSER_H_

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Infix_Evaluator
{
public:
	void parser(string expression);
	void evaluation(stack<char> maths);
private:
	static const string OPERATORS;
	static const string PRECEDENCE;
};

#endif INFIX_EXPRESION_PARSER_H_


