#include <iostream>
#include <iterator>
#include <array>
#include <algorithm>

using namespace std;
#define SIZE 10

bool greater9(int value){
	return value > 9;
}

int main(){
	array< int, SIZE > init = { 10, 2, 10, 4, 16, 6, 14, 8, 12, 10 };
	ostream_iterator<int> output(cout, " ");
	
	//remove
	array<int, SIZE> a1(init);
	cout << "a1 before removing all 10s:\n";
	copy(a1.begin(), a1.end(), output);
	auto newLastElement = remove(a1.begin(), a1.end(), 10);
	cout << "\na1 after removing all 10s:\n";
	copy(a1.begin(), newLastElement, output);
	
	//remove if element greater than 9
	array<int, SIZE> a2(init);
	cout << "\n\na2 before removing all elements greater than 9:\n";
	copy(a2.begin(), a2.end(), output);
	newLastElement = remove_if(a2.begin(), a2.end(), greater9);
	cout << "\na2 after removing all elements greater than 9:\n";
	copy(a2.begin(), newLastElement, output);
	
	//remove_copy
	array<int, SIZE> c1 = {0};
	array<int, SIZE> a3(init);
	cout << "\n\nBefore removing and copying 10s:\n  c1: ";
	copy(c1.begin(), c1.end(), output);
	cout<< "\n  a3: ";
	copy(a3.begin(), a3.end(), output);
	remove_copy(a3.begin(), a3.end(), c1.begin(), 10);
	cout << "\nAfter removing and copying 10s:\n  c1: ";
	copy(c1.begin(), c1.end(), output);
	cout<< "\n  a3: ";
	copy(a3.begin(), a3.end(), output);
	
	//remove_copy if element geater than 9
	array<int, SIZE> c2 = {0};
	array<int, SIZE> a4(init);
	cout << "\n\nBefore removing and copying all elements greater than 9:\n  c2: ";
	copy(c2.begin(), c2.end(), output);
	cout<< "\n  a4: ";
	copy(a4.begin(), a4.end(), output);
	remove_copy_if(a4.begin(), a4.end(), c2.begin(), greater9);
	cout << "\nAfter removing and copying all elements greater than 9:\n  c1: ";
	copy(c2.begin(), c2.end(), output);
	cout<< "\n  a3: ";
	copy(a4.begin(), a4.end(), output);
}





