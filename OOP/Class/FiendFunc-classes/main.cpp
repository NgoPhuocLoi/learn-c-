#include <iostream>

using namespace std;

class Count {
//	friend void setX(Count &c, int value){
//		c.x = value;
//	}
	
	public:
		 Count() : x(0), y(0)
		{
		}
		void print() const {
			cout << x << ", " << y << endl;
		}
		Count* setX(int x){
			this->x = x;
			return this;
		}
		Count* setY(int value){
			y = value;
			return this;
		}
	private:
		int x, y;
};

int main (){
	Count a ;
	a.print();
	a.setX(10)->setY(20)->print();
//	a.print();
	cout << "\nRun";
}
