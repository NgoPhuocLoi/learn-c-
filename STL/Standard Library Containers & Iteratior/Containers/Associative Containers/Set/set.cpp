#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <array>

using namespace std;
#define SIZE 5

int main(){
	array<double, SIZE> values =   { 2.1, 4.2, 9.5, 2.1, 3.7 };
	set<double, less<double>> doubleSet(values.cbegin(), values.cend());
	ostream_iterator<double> output(cout, " ");
	
	// notice that the value 2.1- which appeared twice in array- appears only once in doubleSet
	cout << "doubleSet contains: ";
	copy(doubleSet.cbegin(), doubleSet.cend(), output);
	
	// insert return pair in which
	// +) p.first: const_iterator pointing to the element the set inserted, ( if the values 
	// inserted is already in set, p.first poits to the exist element in set)
	// +) p.second: bool value indicating whether the item was inserted ot not
	auto p = doubleSet.insert(13.8);
	
	cout << "\n\n" << *(p.first)
		<< (p.second ? " was" : " was not") << " inserted\n";
	cout << "doubleSet contains: ";
	copy(doubleSet.cbegin(), doubleSet.cend(), output);
	
	p = doubleSet.insert(9.5);
	
	cout << "\n\n" << *(p.first)
		<< (p.second ? " was" : " was not") << " inserted\n";
	cout << "doubleSet contains: ";
	copy(doubleSet.cbegin(), doubleSet.cend(), output);
}






