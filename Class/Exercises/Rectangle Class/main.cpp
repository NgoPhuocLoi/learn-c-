#include "./Rectangle_v2.h"

using namespace std;

int main(){
	Point sets[N] = {{2,2}, {5, 2}, {2,4}, {5,4}};
	try{
		Rectangle_v2 a(sets);
		cout << "Width: " << a.getWidth() << endl;
		cout << "Length: " << a.getLength() << endl;
		cout << "Perimeter: " << a.getPerimeter() << endl;
		cout << "Area: " << a.getArea() << endl;
		a.draw();
	}catch(invalid_argument &ex){
		cout << ex.what() << endl;;
	}
}
