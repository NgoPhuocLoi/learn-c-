#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>

using namespace std;
#define SIZE 10

int main(){
	array<int, SIZE> a =  { 1,2,3,4,5,6,7,8,9,10 };
	ostream_iterator<int> output(cout, " ");
	
	cout << "a contains:\n";
	copy(a.begin(), a.end(), output);
	
	swap(a[0], a[1]);
	cout << "\na after swapping a[0] with a[1] using swap():\n";
	copy(a.begin(), a.end(), output);
	
	iter_swap(a.begin(), a.begin() + 1);
	cout << "\na after swapping a[0] with a[1] using iter_swap():\n";
	copy(a.begin(), a.end(), output);
	
	swap_ranges(a.begin(), a.begin() + 5, a.begin() + 5);
	cout << "\na after swapping the first five elements with the last five elements:\n";
	copy(a.begin(), a.end(), output);
	
	array<int, SIZE> b =  { 11,12,13,14,15,16,17,18,19,20 };
	swap_ranges(a.begin(), a.begin() + 5, b.begin());
	cout << "\nCan swap between 2 array, a and b after swapping:\na: ";
	copy(a.begin(), a.end(), output);
	cout << "\nb: ";
	copy(b.begin(), b.end(), output);
}
