#ifndef EDIT
#define EDIT

#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include "UI.h"
class GraphicEditor : public Shape {
	//���߿� ��尡 ������ �� �������ε� �ǵ��� �Ѵ�. 
	Shape *pStart; 
	Shape *pLast;
	Shape *p;
public:
	void run();
};
#endif