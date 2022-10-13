#ifndef EDIT
#define EDIT

#include "Rect.h"
#include "Circle.h"
#include "Line.h"
#include "UI.h"
class GraphicEditor : public Shape {
	//나중에 노드가 생성될 때 동정바인딩 되도록 한다. 
	Shape *pStart; 
	Shape *pLast;
	Shape *p;
public:
	void run();
};
#endif