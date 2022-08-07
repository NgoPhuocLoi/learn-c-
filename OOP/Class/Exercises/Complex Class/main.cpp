#include "Complex.h"


using namespace std;

int main(){
	Complex a(1,2);
	Complex b(2.7,3);
	a.print();
	b.print();
	a.add(b);
	a.print();
	b.subtract(a);
	b.print();
	cout << "Run";
}
