#include <iostream>
#include <string>
using namespace std;

class BankAcct {
private:
	double money;
	double rate;
	//double interest;
public:
	BankAcct(double m) { money = m; }
	double getMoney() { return money; }
	virtual ~BankAcct() {}; //소멸자의 가상화
	void deposit(double m) { money += m; }
	void withdraw(double m) { money -= m; }
	virtual double getInterest() { return money * rate; }
	void setRate(double r) { rate = r; }
	double getRate() { return rate; }
	virtual void print() = 0; //print()의 가상화
		

};

class SavingAcct : public BankAcct {
public:
	SavingAcct(int m) : BankAcct(m) {
		setRate(0.09);
	}
	double getinterest() { return getMoney()*getRate(); } //재정의
	void print() {
		cout << "==================" << endl;
		cout << " 저축 예금 계좌" << endl;
		cout << "==================" << endl;
		cout << "예금액 : " << getMoney() << endl;
		
	}
};
class CheckingAcct : public BankAcct {
public:
	CheckingAcct(int m) : BankAcct(m) {
		setRate(0.05);
	}
	double getinterest() { return getMoney()*getRate(); } //재정의
	void print() {
		cout << "==================" << endl;
		cout << " 당좌 예금 계좌" << endl;
		cout << "==================" << endl;
		cout << "예금액 : " << getMoney() << endl;
	}
};

int main() {

	BankAcct* sa = new SavingAcct(5000000); //동적할당 및 upcasting
	BankAcct* ca = new CheckingAcct(10000000);
	
	sa->withdraw(500000);
	ca->withdraw(500000);
	sa->print();
	cout << "이자액 : " << sa->getInterest() << endl;
	ca->print();
	cout << "이자액 : " << ca->getInterest() << endl;
	return 0;
}
