#include <iostream>

using namespace std;

class Employee {
	public:
		Employee(){
			count = 0;
			count++;
		}
		~Employee(){
			count--;
		}
		
		static int getCount(){
			return count;
		}
		
	private:
		static int count;
	
};


int main(){
	cout << Employee::getCount();
	cout << "\nRun";
}
