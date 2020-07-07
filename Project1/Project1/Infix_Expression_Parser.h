#pragma once
#ifndef INFIX_EXPRESSION_PARSER_H_
#define INFIX_EXPRESSION_PARSER_H_

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

class Infix_Evaluator
{
public:
	void parser(string expression);
	
private:
	int eval_operator(char op);
	static const string OPERATORS;
	static const int PRECEDENCE[];
	bool is_operator(char ch) const {
		return OPERATORS.find(ch) != string::npos;
	}
	stack<int> operands_stack;
};

class Syntax_Error : public invalid_argument {
public:
	Syntax_Error(string msg) : invalid_argument(msg) {}
};

#endif


