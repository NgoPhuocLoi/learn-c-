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
	
	//replace
	array<int, SIZE> a1(init);
	cout << "a1 before replacing all 10s with 100:\n";
	copy(a1.begin(), a1.end(), output);
	replace(a1.begin(), a1.end(), 10, 100);
	cout << "\na1 after replacing all 10s with 100:\n";
	copy(a1.begin(), a1.end(), output);
	
	//replace if element greater than 9
	array<int, SIZE> a2(init);
	cout << "\n\na2 before replacing all elements greater than 9 with 100:\n";
	copy(a2.begin(), a2.end(), output);
	replace_if(a2.begin(), a2.end(), greater9, 100);
	cout << "\na2 after replacing all elements greater than 9 with 100:\n";
	copy(a2.begin(), a2.end(), output);
	
	//replace_copy
	array<int, SIZE> c1 = {0};
	array<int, SIZE> a3(init);
	cout << "\n\nBefore replacing and copying 10s with 100:\n  c1: ";
	copy(c1.begin(), c1.end(), output);
	cout<< "\n  a3: ";
	copy(a3.begin(), a3.end(), output);
	replace_copy(a3.begin(), a3.end(), c1.begin(), 10, 100);
	cout << "\nAfter replacing and copying 10s with 100:\n  c1: ";
	copy(c1.begin(), c1.end(), output);
	cout<< "\n  a3: ";
	copy(a3.begin(), a3.end(), output);
	
	//remove_copy if element geater than 9
	array<int, SIZE> c2 = {0};
	array<int, SIZE> a4(init);
	cout << "\n\nBefore replacing and copying all elements greater than 9 with 100:\n  c2: ";
	copy(c2.begin(), c2.end(), output);
	cout<< "\n  a4: ";
	copy(a4.begin(), a4.end(), output);
	replace_copy_if(a4.begin(), a4.end(), c2.begin(), greater9, 100);
	cout << "\nAfter replacing and copying all elements greater than 9 with 100:\n  c1: ";
	copy(c2.begin(), c2.end(), output);
	cout<< "\n  a3: ";
	copy(a4.begin(), a4.end(), output);
}





