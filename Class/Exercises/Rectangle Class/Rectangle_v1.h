#include <iostream>
#include <stdexcept>

#ifndef RECTANGLE_V1
#define RECTANGLE_V1 1

class Rectangle_v1 {
	public:
		Rectangle_v1(double l = 1, double w = 1){
			setLength(l);
			setWidth(w);
		}
		
		void setLength(double l){
			if(l > 0 && l < 20)
				length = l;
			else throw std::invalid_argument("Invalid length! (Length must be in range (0, 20))");
		}
		
		void setWidth(double w){
			if(w > 0 && w < 20)
				width = w;
			else throw std::invalid_argument("Invalid width! (Width must be in range (0, 20))");
		}
		
		double calcPerimeter() const {
			return (width + length)*2;
		}
		
		double calcArea() const {
			return width*length;
		}
 
	private:
		double length, width;
};

#endif



