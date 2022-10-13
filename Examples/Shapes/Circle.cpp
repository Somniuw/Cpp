#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int Radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }

};

class NamedCircle : Circle {
	string title;
public:
	NamedCircle(int radius, string title) : Circle (radius)
	{
		this->title = title;
	}
	void show() {
		cout << "반지름이 " << getRadius() << "인 " << this->title << endl;
	}
};

int main()
{
	NamedCircle waffle(3, "waffle");
	waffle.show();
}
