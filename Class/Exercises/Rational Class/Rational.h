#include <iostream>
#include <stdexcept>

#ifndef RATIONAL
#define RATIONAL 1

class Rational{
	public:
		Rational(int a = 1, int b = 1)
		{
			if(b != 0){
				numerator = a;
				denominator = b;
				reduce(numerator, denominator);
			}else{
				throw std::invalid_argument("Denominator is not allowed equal 0!");
			}
		}
		
		void add(Rational b){
			numerator = numerator*b.denominator + b.numerator*denominator;
			denominator *= b.denominator;
			reduce(numerator, denominator);
		}
		
		void substract(Rational b){
			numerator = numerator*b.denominator - b.numerator*denominator;
			denominator *= b.denominator;
			reduce(numerator, denominator);
		}
		
		void multiply(Rational b){
			numerator *= b.numerator;
			denominator *= b.denominator;
			reduce(numerator, denominator);
		}
		
		void divide(Rational b){
			numerator *= b.denominator;
			denominator *= b.numerator;
			reduce(numerator, denominator);
		}
		
		void printFration() const {
			if(numerator % denominator == 0){
				std::cout << numerator/denominator << std::endl;
			}else{
				std::cout << numerator << "/" << denominator << std::endl;
			}
		}
		
		void printFloatingPoint() const {
			std::cout << static_cast<double>(numerator)/denominator << std::endl;
		}
	
	private:
		int numerator;
		int denominator;
		
		unsigned int GCD(int a, int b){
			if(a < 0) a = -a;
			if(b < 0) b = -b;
			while(b != 0){
				int temp = a % b;
				a = b;
				b = temp;
			}
			return a;
		}
		
		void reduce(int &numerator, int &denominator){
			int gcd = GCD(numerator, denominator);
			numerator /= gcd;
			denominator /= gcd;
		}
};

#endif
