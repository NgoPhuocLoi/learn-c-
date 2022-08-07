#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;
#define SIZE 11

int main(){
	array<int, SIZE> values =  { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13, 22 };
	multiset<int, less<int>> intMultiset;
	ostream_iterator<int> output(cout, " ");
	
	cout << "There are currently " << intMultiset.count(15) 
		<< " values of 5 in the intMultiset\n";
		
	intMultiset.insert(15);
	intMultiset.insert(15);
	
	
	cout << "After insert, there are " << intMultiset.count(15) 
		<< " values of 5 in the intMultiset\n";
		
	cout << "The set: ";
	copy(intMultiset.cbegin(), intMultiset.cend(), output);
	
	
	auto result = intMultiset.find(15);	
	cout << "nFind return value: " << *(result) << endl;
	if(result != intMultiset.end()){
		cout << "\nFound value 15\n";
	}	
	
	result = intMultiset.find(20);	
	if(result == intMultiset.end()){
		cout << "Did not find value 20\n";
	}
	
	intMultiset.insert(values.cbegin(), values.cend());
	cout << "After insert values, multiset contains: ";
	copy(intMultiset.cbegin(), intMultiset.cend(), output);
	
	
	// determine lower_bound, upper_bound
	cout << "\n\nLower bound of 22: " << *(intMultiset.lower_bound(22));
	cout << "\nUpper bound of 22: " << *(intMultiset.upper_bound(22));
	
	// use equal_range to determine lower and upper bound
	auto p = intMultiset.equal_range(22);
	cout << "\nEqual range of 22:\n\tLower bound: " << *(p.first)
			<< "\n\tUpper bound: " << *(p.second);
	
	
	cout << "\n\nRun";
}






