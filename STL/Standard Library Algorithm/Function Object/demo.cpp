#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>

using namespace std;

int sumSquares(int total, int value){
	return total + value*value;
}

template <typename T>
class SumSquaresClass{
	public:
		T operator()(T total, T value){
			return total + value*value;
		}
};

int main(){
	array<int, 10> integers =  { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ostream_iterator<int> output(cout, " ");
	
	cout<< "integers contains:\n";
	copy(integers.begin(), integers.end(), output);
	
// accummlate with binary function sumSquares (pointer function)
	int result = accumulate(integers.begin(), integers.end(), 0, sumSquares);
	cout << "\n\nSum of squares of elements in integers\n"
		"using binary function sumSquares: " << result;
		
// accummlate with binary function object
	result = accumulate(integers.begin(), integers.end(), 0, SumSquaresClass<int>());
	cout << "\n\nSum of squares of elements in integers\n"
		"using binary function object of type SumSquaresClass<int>: " << result;
}















