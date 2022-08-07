#include <iostream>
#include <vector>

using namespace std;

template <typename T> void printVector(const vector<T> &inputVector){
	for(auto constIterator = inputVector.cbegin(); 
		constIterator != inputVector.cend(); ++constIterator)
	{
		cout << *constIterator << " ";
	}
	cout << endl;
}

int main(){
	const int SIZE = 6;
	int values[SIZE] = {1,2,3,4,5,6};
	vector<int> integers;
	
	cout << "The initial size of integers is: " << integers.size() << endl;
	cout << "The initial capacity of integers is: " << integers.capacity() << endl;
	
	// display the array using pointer position
	cout << "Output built-in array using pointer notation: ";
	for(const int *intPtr = begin(values); intPtr != end(values); ++intPtr){
		cout << *intPtr << " ";
	}
	
	integers.push_back(3);
	integers.push_back(7);
	integers.push_back(9);
	integers.push_back(9);
	integers.push_back(9);
	
	integers.reserve(6);
	
	cout << "\nThe current size of integers is: " << integers.size() << endl;
	cout << "The current capacity of integers is: " << integers.capacity() << endl;
	
	// output vector using iterator notation
	cout << "Output vector using iterator notation: ";
	printVector(integers);
	
	cout << "Reverse content of vector: ";
	for(auto rcIterator = integers.crbegin(); rcIterator != integers.crend(); ++rcIterator)
	{
		cout << *rcIterator << " ";
	}
	
	cout << "\nRun";
}


