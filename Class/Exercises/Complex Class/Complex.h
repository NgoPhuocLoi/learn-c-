#include <iostream>

#ifndef COMPLEX
#define COMPLEX 1

class Complex {
	public:
		Complex(double real = 0, double image = 0)
			:real(real), image(image)
		{
		}		
		
		void add(Complex b){
			real += b.real;
			image += b.image;
		}
		
		void subtract(Complex b){
			real -= b.real;
			image -= b.image;
		}
		
		void print() const {
			std::cout << "(" << real << ", " << image << ")\n";
		}
	
	private:
		double real;
		double image;
};

#endif
