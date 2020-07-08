#include "Infix_Expression_Parser.h"

const string Infix_Evaluator::OPERATORS = "( ) ! ++ -- - ^ * / % + - > >= < <= == != && ||";
const int Infix_Evaluator::PRECEDENCE[] = { 9, 9, 8, 8, 8, 8, 7, 6, 6, 6, 5, 5, 4, 4, 4, 4, 3, 3, 2, 1 };

void Infix_Evaluator::parser(string expression)
{	
	istringstream token(expression);
	char next_char;
    int num, result;
	while(token >> next_char)
	{
        try
        {
            if (isdigit(next_char))
            {
                token.putback(next_char);
                token >> num;
                operands_stack.push(num);
            }
            else if (is_operator(next_char))
            {

                if (operators_stack.empty())
                {
                    operators_stack.push(next_char);
                    cout << "pushed operator into stack" << endl;
                
                }
                else if (!operators_stack.empty())
                {
                    if (precedence(next_char) > precedence(operators_stack.top()))
                    {
                        result = eval_operator(next_char);
                        operands_stack.push(result);
                        cout << "evaluated operator, precedence was higher" << endl;
                    }
                    else
                    {
                        result = eval_operator(operators_stack.top());
                        operands_stack.push(result);
                        operators_stack.push(next_char);
                        cout << "evaluated operator, precedence was lower" << endl;
                    }
                    
                    
                }
                else
                {
                    cout << "did nothing" << endl;
                }
            }
            else
            {
                throw runtime_error("Invalid character encountered");
            }
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
            exit(1);
        }   
	}
    if (!operators_stack.empty())
    {
        result = eval_operator(operators_stack.top());
        operands_stack.push(result);
        cout << "evaluated operator outside while loop" << endl;
    }
    
    cout << operands_stack.top() << endl;
}

int Infix_Evaluator::eval_operator(char op)
{
    int result = 0;

    try
    {
        if (operands_stack.empty())
            throw runtime_error("Stack is empty");
    }
    catch (runtime_error& e)
    {
        cout << e.what() << endl;
        exit(2);
    }
    
    int rhs = operands_stack.top();
    operands_stack.pop();
    try
    {
        if (operands_stack.empty())
            throw runtime_error("Stack is empty");
    }
    catch (runtime_error& e)
    {
        cout << e.what() << endl;
        exit(2);
    }
    int lhs = operands_stack.top();
    operands_stack.pop();
    switch (op) {
    case '+': result = lhs + rhs;
        break;
    case '-': result = lhs - rhs;
        break;
    case '*': result = lhs * rhs;
        break;
    case '/': result = lhs / rhs;
        break;
    case '%': result = lhs % rhs;
        break;
    case '^': result = pow(lhs, rhs);
    }
    cout << "did maths" << endl;


    return result;
}