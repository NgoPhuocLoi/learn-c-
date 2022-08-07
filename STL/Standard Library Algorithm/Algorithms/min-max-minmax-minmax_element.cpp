#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
#define SIZE 10

int main(){
// min, max
	cout << "min(7,12) = " << min(7,12);
	cout << "\nmax(7,12) = " << max(7,12);
	cout << "\nmin('G','Z') = " << min('G','Z');
	cout << "\nmax('G','Z') = " << max('G','Z');
	
// minmax
	auto result1 = minmax(4, 7);
	cout << "\nThe minimum of 4 and 7 is " << result1.first;	
	cout << "\nThe maximum of 4 and 7 is " << result1.second;	
	
	auto result2 = minmax({1,9,2,4,6,33,2,-23});
	cout << "\nThe minimum in {1,9,2,4,6,33,2,-23} is " << result2.first;	
	cout << "\nThe maximum in {1,9,2,4,6,33,2,-23} is " << result2.second;

// minmax_element
	array< int, 10 > items = { 3, 100, 52, 77, 22, 31, 1, 98, 13, 40 };
	ostream_iterator<int> output(cout, " ");
	cout << "\n\nArray items contains: \n";
	copy(items.begin(), items.end(), output);
	
	auto result3 = minmax_element(items.begin(), items.end());
	cout << "\nThe minimum in items is " << *(result3.first)
		<< " (at location " << (result3.first - items.begin()) << ")";
	cout << "\nThe maximum in items is " << *(result3.second)
		<< " (at location " << (result3.second - items.begin()) << ")";
	
}
