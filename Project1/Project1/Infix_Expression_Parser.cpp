#include "Infix_Expression_Parser.h"

const string Infix_Evaluator::OPERATORS = "( ! ++ -- - ^ * / % + - > >= < <= == != && ||";
const int Infix_Evaluator::PRECEDENCE[] = { 9, 8, 8, 8, 8, 7, 6, 6, 6, 5, 5, 4, 4, 4, 4, 3, 3, 2, 1 };

void Infix_Evaluator::parser(string expression)
{	
	istringstream token(expression);
	char next_char;
	int num;
	while(token >> next_char)
	{
        if (isdigit(next_char)) {
            token.putback(next_char);
            token >> num;
            operands_stack.push(num);
        }
        else if (is_operator(next_char))
        {
            cout << "is operator" << endl;
        }
        else
        {
            cout << "invalid character in the expression" << endl;
        }
	}
	
}

int Infix_Evaluator::eval_operator(char op)
{
    int result = 0;



    return result;
}