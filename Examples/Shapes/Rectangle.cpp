#include <iostream>
#include <string>
using namespace std;

//defines rectangle class
class Rectangle {
private:
	int Width;
	int Height;
	int Area;
public:
	Rectangle(int, int);
	void computeArea();
	int getWidth();
	int getHeight();
	int getArea();
};

Rectangle::Rectangle(int w, int h) : Width(w), Height(h) {}

//computes a rectangle's area
void Rectangle::computeArea() {Area = Width * Height;}

//gets a rectangle's area, height, and width
int Rectangle::getArea() {return Area;}
int Rectangle::getHeight() {return Height;}
int Rectangle::getWidth() {return Width;}


int main() {
	Rectangle r1(2,5), r2(3,8);
	r1.computeArea(), r2.computeArea();
	cout << "R1 - Width: " << r1.getWidth() << "   Height: " << r1.getHeight() << "   Area: " << r1.getArea() << endl;
	cout << "R2 - Width: " << r2.getWidth() << "   Height: " << r2.getHeight() << "   Area: " << r2.getArea() << endl;
	return 0;
}
