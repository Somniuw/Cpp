#include <iostream>
using namespace std;

class AbstractGate { // 추상 클래스
protected:
	bool x, y;
public:
	void set(bool x, bool y) {
		this->x = x;
		this->y = y;
	}
	virtual bool operation() = 0; // 순수 가상 함수
	virtual ~AbstractGate() {}; //아래에는 해줄 필요 없다. 기본 클래스에만 해줘도 아래에서 수행.
};

class ANDGate : public AbstractGate {
public:
	bool operation() {
		return x && y;
	}
};

class ORGate : public  AbstractGate {
public:
	bool operation() {
		return x || y;
	}
};

class XORGate : public AbstractGate {
public:
	bool operation() {
		return x^y;
	}
};

int main() {
	ANDGate AND;
	ORGate OR;
	XORGate XOR;

	AND.set(true, false), OR.set(true, false), XOR.set(true, false);
	AbstractGate *ap[] = { new ANDGate(), new ORGate(), new XORGate() };
	// Boolean 값을 "true”, "false" 로 출력할 것을 지시
	cout.setf(ios::boolalpha);
  
	for (AbstractGate *p : ap){
		p->set(true, false);
		cout << p->operation() << endl;
	}
	for (AbstractGate *p : ap){
		delete p;
	}
}
