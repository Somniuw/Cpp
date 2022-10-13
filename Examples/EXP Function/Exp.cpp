#include <string>
#include <iostream>
#include "Exp.h"

Exp::Exp(int b, int e) { base = b, exp = e; }
Exp::Exp(int b) { base = b, exp = 1; }
Exp::Exp() { base = 1, exp = 1; }



int Exp::getExp()
{
	return exp;
}
int Exp::getBase()
{
	return base;
}
int Exp::getValue()
{
	int res = 1;
	for (int i = 0; i < exp; i++)
		res = res * base;

	return res;
}
bool Exp::equals(Exp b)
{
	if (getValue() == b.getValue())
		return 1;
	else
		return 0;
}