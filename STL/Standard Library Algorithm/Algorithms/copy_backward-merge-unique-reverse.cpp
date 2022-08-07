#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

using namespace std;
#define SIZE 5


int main(){
	array<int, SIZE> a1 = {2, 4, 5 ,7 ,9};
	array<int, SIZE> a2 = {1, 3, 5 ,7 ,9};
	array<int, SIZE> results;
	ostream_iterator<int> output(cout, " ");
	
	cout << "a1 contains:\n";
	copy(a1.begin(), a1.end(), output);
	cout << "\na2 contains:\n";
	copy(a2.begin(), a2.end(), output);

// copy_backward
	copy_backward(a1.begin(), a1.end(), results.end());
	cout << "\nAfter copy_backward a1 to result, results contains:\n";
	copy(results.begin(), results.end(), output);
// merge
	array<int, SIZE+SIZE> result2;
	merge(a1.begin(), a1.end(), a2.begin(), a2.end(), result2.begin());
	cout << "\nAfter merge of a1 and a2, result2 contains:\n";
	copy(result2.begin(), result2.end(), output);
//unique
	auto lastElement = unique(result2.begin(), result2.end());
	cout << "\nAfter unique, result2 contains:\n";
	copy(result2.begin(), lastElement, output);
//reverse
	reverse(a1.begin(), a1.end());
	cout << "\na1 after reverse:\n";
	copy(a1.begin(), a1.end(), output);
}
