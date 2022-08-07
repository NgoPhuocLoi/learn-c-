#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

using namespace std;

#define SIZE 5

bool myPredicate(int i, int j){
	return i > j;
}

int main(){
	array<int, SIZE> a1 = {1,4,5,7,6};
	array<int, SIZE> a2(a1);
	array<int, SIZE> a3 = {1,4,5,11,3};
	array<int, SIZE> a4 = {0,2,4,1,5};
	ostream_iterator<int> output(cout, " ");
	
	cout << "a1 contains: ";
	copy(a1.begin(), a1.end(), output);
	cout << "\na2 contains: ";
	copy(a2.begin(), a2.end(), output);
	cout << "\na3 contains: ";
	copy(a3.begin(), a3.end(), output);
	cout << "\na3 contains: ";
	copy(a4.begin(), a4.end(), output);
	
	cout << "\n\n===EQUAL===";
	// equal version 1 (3 params)
	bool result = equal(a1.begin(), a1.end(), a2.begin());
	cout << "\na1 " << ( result ? "is" : "is not" ) << " equal to a2.\n";
	
	result = equal(a1.begin(), a1.end(), a3.begin());
	cout << "a1 " << ( result ? "is" : "is not" ) << " equal to a3.\n";
	
	//equal version 2 (4 params)
	result = equal(a1.begin(), a1.end(), a4.begin(), myPredicate);
	cout << "all a1[i] " << (result ? "greater" : "lower") << " than a4[i]\n";
	
	//has 2 version same with equal
	cout << "\n\n===MISMATCH===";
	auto location = mismatch(a1.begin(), a1.end(), a3.begin());
	cout << "\nThere is a mismatch between a1 and a3 at location " 
		<< (location.first - a1.begin()) << "\nwhere a1 contains "
		<< *(location.first) << " and a3 contains" << *(location.second);
	
	result = equal(a1.begin(), a1.end(), a3.begin());
	cout << "a1 " << ( result ? "is" : "is not" ) << " equal to a3.\n";

	cout << "\n\n===LEXICOGRAPHICAL_COMPARE===\n";
	char c1[] = "HELLO";
	char c2[] = "BYE BYE";
	result = lexicographical_compare(begin(c1), end(c1), begin(c2),end(c2));
	cout << c1 << " is " << ((result) ? "less" : "greater") << " than " << c2;
	
}





