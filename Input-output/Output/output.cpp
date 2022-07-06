#include <iostream>
using namespace std;

int main(){
  // cout char* variable	
	const char* word = "Hello";
	cout << word << endl; // display value
	cout << static_cast<const void*>(word); // display address
	
	// 'put' member function -> display a character
	cout.put('\n');
	cout.put('L').put('O').put(73);


  // scientific and fixed notation
  double number1 = 0.00012345;
  double number2 = 1.946e9;

  cout << "Display in default format: \n" << number1 << '\t' << number2 << endl;
  cout << "Display in scientific format: \n" << scientific <<number1 << '\t' << number2 << endl;
  cout << "Display in fixed format: \n" << fixed<< number1 << '\t' << number2 << endl;

  // uppercase hexadecial and exponent 
  cout << "\n Printing uppercase letters in scientific notation exponents and hexadecial: \n";
  cout << uppercase << scientific <<1.23e9 << '\t' 
        << hex << showbase << 2003 << endl;

}
