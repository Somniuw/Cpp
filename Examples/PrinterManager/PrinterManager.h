#ifndef MANAGER
#define MANAGER

#include "printer.h"
#include "InkjetPrinter.h"
#include "LaserPrinter.h"
#include "LinePrinter.h"

class PrinterManager
{
//�� �������� ��ü�� �ϳ��� ����
protected:
	//�����ο��� ��ĳ������ �Ͼ����.
	Printer* ink;
	Printer* laser;
	Printer* line;
public:
	PrinterManager();
	void info();
	void add(); //��ũ/���/�巳 ���� �޴�
	void pAdd(); //���� ���� �޴�
	void printit(); //����Ʈ �޴�
	void terminate(); //���α׷� ����
};
#endif
