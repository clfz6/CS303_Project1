#include "Infix_Expression_Parser.h"

const string Infix_Evaluator::OPERATORS = "( ) ! ++ -- - ^ * / % + - > >= < <= == != && ||";
const int Infix_Evaluator::PRECEDENCE[] = { 9, 9, 8, 8, 8, 8, 7, 6, 6, 6, 5, 5, 4, 4, 4, 4, 3, 3, 2, 1 };

void Infix_Evaluator::parser(string expression)
{	
	istringstream token(expression);
	char next_char, n_next_char, nn_next_next;
    int num, result;
    element = 0;
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
                token >> n_next_char;
                if (is_operator(n_next_char) || n_next_char == '=')
                {
                    try
                    {
                        token >> nn_next_next;
                        if (isdigit(nn_next_next))
                        {
                            token.putback(nn_next_next);
                            token >> num;
                            operands_stack.push(num);
                            element++;
                        }
                        else
                        {
                            throw runtime_error("Too many operators in a row @ char " + element);
                        }
                    }
                    catch (runtime_error& e)
                    {
                        cout << e.what() << endl;
                        exit(3);
                    }
                    result = eval_double_char_operator(next_char, n_next_char);
                    operands_stack.push(result);
                    element++;
                }
                else
                {
                    token.putback(n_next_char);
                }

                if (operators_stack.empty())
                {
                    operators_stack.push(next_char);
                
                }
                else if (!operators_stack.empty())
                {
                    if (precedence(next_char) > precedence(operators_stack.top()))
                    {
                        result = eval_operator(next_char);
                        operands_stack.push(result);
                    }
                    else
                    {
                        result = eval_operator(operators_stack.top());
                        operands_stack.push(result);
                        operators_stack.push(next_char);
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
        element++;
	}
    if (!operators_stack.empty())
    {
        result = eval_operator(operators_stack.top());
        operands_stack.push(result);
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
    case '/': 
        try
        {
            if (rhs == 0)
            {
                throw runtime_error("Division by zero @ char " + element);
            }
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
            exit(3);
        }
        result = lhs / rhs;
        break;
    case '%': result = lhs % rhs;
        break;
    case '^': result = pow(lhs, rhs);
    }

    return result;
}

int Infix_Evaluator::eval_double_char_operator(char char1, char char2)
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

    if (char1 == '+' && char2 == '+')
    {
        int rhs = operands_stack.top();
        operands_stack.pop();
        result = ++rhs;
    }
    else if (char1 == '-' && char2 == '-')
    {
        int rhs = operands_stack.top();
        operands_stack.pop();
        result = --rhs;
    }

    return result;
}