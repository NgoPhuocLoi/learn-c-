#include <iostream>
#include <stdexcept>
#include <math.h>

#ifndef RECTANGLE_V2
#define RECTANGLE_V2 1
#define N 4

struct Point {
	double x, y;
};

class Rectangle_v2 {
	public:
		Rectangle_v2(Point sets[]){
//			int size = sizeof(sets)/sizeof(sets[0]);
//			std::cout << "size: " << std::begin(sets) << std::endl;
//			if(size != N) throw std::invalid_argument("The number of corners must be 4!");
			setCorners(sets);
			
		}
		
		void setCorners(Point sets[]){
			double squareDistance[3];
			
			for(int i = 0; i < N; i++){
				if(!isValidPoint(sets[i]))
					throw std::invalid_argument("The corner must be in the first quadrant with no single x- or y-coordinate larger than 20.0!");
			}
			
			for(int i = 0; i < 3; i++){
				squareDistance[i] = getSquareDistance(sets[0], sets[i+1]);
			} 
			
			sort(squareDistance, 3);
				
			bool isRectangle = squareDistance[0] + squareDistance[1] == squareDistance[2];
			if(!isRectangle)
				throw std::invalid_argument("The supplied points do not specify a rectangle!");
			
			// valid points
			width = sqrt(squareDistance[0]);
			length = sqrt(squareDistance[1]);
		}
		
		bool isSquare() const {
			return width == length;
		}

		double getWidth() const {
			return width;
		}
		
		double getLength() const {
			return length;
		}
		
		double getPerimeter() const {
			return (width + length)*2;
		}
		
		double getArea() const {
			return width*length;
		}
		
		void draw() const {
			for(int i = 1; i <= width; i++){
				for(int j = 1; j <= length; j++){
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
		}
	private:
		double length, width;
		
		double getSquareDistance(Point a, Point b){
			return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
		}
		
		void sort(double a[], int n){
			for(int i = 1; i < n; i++){
				for(int j = 0; j < n -1; j++){
					if(a[j] > a[j+1]){
						double temp = a[j];
						a[j] = a[j+1];
						a[j+1] = temp;
					}
				}
			}
		}
		
		bool isValidPoint(Point a){
			return a.x >= 0 && a.y  >= 0 && a.x < 20 && a.y < 20;
		}
};

#endif



