#include "Infix_Expression_Parser.h"

int main()
{
	Infix_Evaluator eval;
	eval.parser("42 + 5 ");

	return 0;
}