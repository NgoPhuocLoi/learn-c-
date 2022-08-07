#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
#define SIZE 10

int main(){
	array<int, SIZE> a1 =  { 1, 3, 5, 7, 9, 1, 3, 5, 7, 9 };
	ostream_iterator<int> output(cout, " ");
	
	cout << "array contains:\n";
	copy(a1.begin(), a1.end(), output);
	
	// merge first half of a1 with second half of a1 such that
	// a1 contains sorted set of elements after merge
	inplace_merge( a1.begin(), a1.begin() + 5, a1.end() );
	cout << "\nAfter merge, array contains:\n";
	copy(a1.begin(), a1.end(), output);
	
	vector<int> result1;
	unique_copy(a1.begin(), a1.end(), back_inserter(result1));
	cout << "\nAfter unique_copy, result1 contains:\n";
	copy(result1.begin(), result1.end(), output);
	
	vector<int> result2;
	reverse_copy(a1.begin(), a1.end(), back_inserter(result2));
	cout << "\nAfter reverse_copy, result1 contains:\n";
	copy(result2.begin(), result2.end(), output);
}
