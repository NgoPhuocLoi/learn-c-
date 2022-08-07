#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>

using namespace std;
#define SIZE 10

bool greater10(int x){
	return x > 10;
}

bool greater100(int x){
	return x > 100;
}

bool myCompareFunc(int x, int y){
	return x > y;
}

int main(){
	array<int, SIZE> a =  { 10, 2, 17, 5, 16, 8, 13, 11, 20, 7 };
	ostream_iterator<int> output(cout, " ");
	
	cout << "array contains:\n";
	copy(a.begin(), a.end(), output);

// find, find_if, find_if_not
	cout << "\n\n====FIND====";
	// find
	auto location = find(a.begin(), a.end(), 16);
	if(location != a.end()){
		cout << "\nFound 16 at location " << (location - a.begin());
	}else{
		cout << "\nNot found 16";
	}
	
	location = find(a.begin(), a.end(), 100);
	if(location != a.end()){
		cout << "\nFound 100 at location " << (location - a.begin());
	}else{
		cout << "\nNot found 100";
	}
	// find_if
	location = find_if(a.begin(), a.end(), greater10);
	if(location != a.end()){
		cout << "\nThe first value greater than 10 is " << *location
			<< ", at location " << (location - a.begin());
	}else{
		cout << "\nNo values greater than 10";
	}
	
	location = find_if(a.begin(), a.end(), greater100);
	if(location != a.end()){
		cout << "\nThe first value greater than 100 is " << *location
			<< ", at location " << (location - a.begin());
	}else{
		cout << "\nNo values greater than 100";
	}
	// find_if_not
	location = find_if_not(a.begin(), a.end(), greater10);
	if(location != a.end()){
		cout << "\nThe first value not greater than 10 is " << *location
			<< ", at location " << (location - a.begin());
	}else{
		cout << "\nAll values is greater than 10";
	}
	
// sort, binary_search
	cout << "\n\n====SORT AND SEARCH====";
	sort(a.begin(), a.end());
	cout << "\narray after sorts ascending:\n";
	copy(a.begin(), a.end(), output);
	
	sort(a.begin(), a.end(), myCompareFunc);
	cout << "\narray after sorts descending:\n";
	copy(a.begin(), a.end(), output);
	
	cout << "\nUsing binary_search:";
	sort(a.begin(), a.end());
	if(binary_search(a.begin(), a.end(), 13)){
		cout << "\n\t13 was found in array";
	}else{
		cout << "\n\t13 was not found";
	}
	
	if(binary_search(a.begin(), a.end(), 100)){
		cout << "\n\t100 was found in array";
	}else{
		cout << "\n\t100 was not found";
	}
	
// all_of, any_of, none_of
	cout << "\n\n====ALL_OF, ANY_OF, NONE_OF====";	
	if(all_of(a.begin(), a.end(), greater10)){
		cout <<"\nAll the elements in a are greater than 10";
	}else{
		cout <<"\nSome elements in a are not greater than 10";
	}
	
	if(any_of(a.begin(), a.end(), greater10)){
		cout <<"\nSome elements in a are greater than 10";
	}else{
		cout <<"\nNone of the elements in a are not greater than 10";
	}
	
	if(none_of(a.begin(), a.end(), greater10)){
		cout <<"\nNone of the elements in a are greater than 10";
	}else{
		cout <<"\nSome elements in a are greater than 10";
	}
}
