#include <iostream>
#include <string>
#include <iomanip>

#ifndef PHONE_NUMBER
#define PHONE_NUMBER 1

class PhoneNumber {
	// input form (123) 456-7890
	friend std::istream & operator>>(std::istream &input, PhoneNumber &number){
		input.ignore(); // ignore (
		input >> std::setw(3) >> number.areaCode;
		input.ignore(2); // ignore ) and space
		input >> std::setw(3) >> number.exchange;
		input.ignore(); // ignore -
		input >> std::setw(4) >> number.line;
		input.ignore();
		
		return input; // enable cascaded function call (cin >> a >> b >> c)
	}
	
	friend std::ostream & operator << (std::ostream &output, PhoneNumber &number){
		output << "(" << number.areaCode << ") "
				<< number.exchange << "-" << number.line;
		return output;
	}
	
	public:


	private:
		std::string areaCode;
		std::string exchange;
		std::string line;
};

#endif



