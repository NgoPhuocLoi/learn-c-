#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;
#define SIZE 10

int main(){
	array<int, SIZE> a = {2,2,4,4,4,6,6,6,6,8};
	ostream_iterator<int> output(cout, " ");
	
	cout << "array contains: \n";
	copy(a.begin(), a.end(), output);
	
	auto lower = lower_bound(a.begin(), a.end(), 6);
	auto upper = upper_bound(a.begin(), a.end(), 6);
	
	cout << "\n\nLower bound of 6 is element " << (lower - a.begin())
		 << " of array";
	cout << "\nLower bound of 6 is element " << (lower - a.begin())
		 << " of array";
		 
	cout << "\n\nUsing equal_range:";
	auto eq = equal_range(a.begin(), a.end(), 6);
	cout << "\n   Lower bound of 6 is element " << (eq.first - a.begin())
		 << " of array";
	cout << "\n   Lower bound of 6 is element " << (eq.second - a.begin())
		 << " of array";
		 
	
	cout << "\n\nUse lower_bound to locate the first\n"
		"point at which 5 can be inserted in order: ";
	lower = lower_bound(a.begin(), a.end(), 5);
	cout << "\n   Lower bound of 5 is element " << (lower - a.begin()) << " of array";
	
	cout << "\n\nUse lower_bound to locate the last\n"
		"point at which 7 can be inserted in order: ";
	upper = upper_bound(a.begin(), a.end(), 7);
	cout << "\n   Lower bound of 7 is element " << (upper - a.begin()) << " of array";
	
	cout << "\n\nUse equal_range to locate the first and last point\n"
			"at which 5 can be inserted in order:";
	eq = equal_range(a.begin(), a.end(), 5);
	cout << "\n   Lower bound of 5 is element " << (eq.first - a.begin())
		 << " of array";
	cout << "\n   Lower bound of 5 is element " << (eq.second - a.begin())
		 << " of array";
}
