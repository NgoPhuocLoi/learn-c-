#include "Rational.h"

using namespace std;

int main(){
	Rational a(9,2);
	Rational b(6,7);
	a.printFration();
	b.printFration();
	a.divide(b);
	a.printFration();

//	try{
//		Rational b(2,0);
//	}catch(invalid_argument &ex){
//		cout << ex.what() <<endl;;
//	}
	cout << "RUn";
}
