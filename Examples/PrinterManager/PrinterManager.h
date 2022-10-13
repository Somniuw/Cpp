#ifndef MANAGER
#define MANAGER

#include "printer.h"
#include "InkjetPrinter.h"
#include "LaserPrinter.h"
#include "LinePrinter.h"

class PrinterManager
{
//각 프린터의 객체를 하나씩 생성
protected:
	//구현부에서 업캐스팅이 일어나도록.
	Printer* ink;
	Printer* laser;
	Printer* line;
public:
	PrinterManager();
	void info();
	void add(); //잉크/토너/드럼 보충 메뉴
	void pAdd(); //용지 보충 메뉴
	void printit(); //프린트 메뉴
	void terminate(); //프로그램 종료
};
#endif
