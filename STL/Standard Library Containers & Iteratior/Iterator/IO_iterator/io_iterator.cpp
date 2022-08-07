#include <iostream>
#include <iterator>

using namespace std;

int main(){
	istream_iterator<int> inputInt(cin);
	int number1 = *(inputInt++);
	int number2 = *inputInt;
	cout << "The sum is: ";
	ostream_iterator<int> outputInt(cout);
	*outputInt = number1 + number2;
	
}
