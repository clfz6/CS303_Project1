#pragma once
#ifndef INFIX_EXPRESSION_PARSER_H_
#define INFIX_EXPRESSION_PARSER_H_

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Infix_Evaluator
{
public:
	void parser(string expression);
	
private:
	stack<int> operands_stack;
	stack<char> operators_stack;
	int eval_operator(char op);
	int eval_double_char_operator(char char1, char char2);
	static const string OPERATORS;
	static const int PRECEDENCE[];
	bool is_operator(char ch) const {
		return OPERATORS.find(ch) != string::npos;
	}
	int precedence(char op) const {
		return PRECEDENCE[OPERATORS.find(op)];
	}
	int element;
};

#endif


