#include <iostream>
#include "DivideByZeroException.h"

using namespace std;

double quotient(int numerator, int denominator){
	if(denominator == 0)
		throw DivideByZeroException();
	
	return numerator*1.0/denominator;
}

int main(){
	int num1, num2;
	cout << "Enter 2 integers (end-of-file to end):\n$ ";
	while(cin >> num1 >> num2){
		try{
			cout << quotient(num1, num2);
			
		}catch(DivideByZeroException &ex){
			cout << "Exception occurred: " << ex.what() << endl;
		}
		cout << "\nEnter 2 integers (end-of-file to end):\n$ ";
	}
}
