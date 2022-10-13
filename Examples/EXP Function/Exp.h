#ifndef EXP_H
#define EXP_H
// 제곱(^) 연산자는 존재하지 않는다.
class Exp {
	int exp;
	int base;
public:
	Exp(int b, int e);
	Exp(int b);
	Exp();

	int getExp();
	int getBase();
	int getValue();
	bool equals(Exp b);
};
#endif

