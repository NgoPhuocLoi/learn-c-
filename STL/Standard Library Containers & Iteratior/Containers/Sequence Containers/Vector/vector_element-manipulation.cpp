#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>
#include <algorithm>
#include <iterator>


using namespace std;

int main(){
	const int SIZE = 6;
	array<int, SIZE> values = {1,2,3,4,5,6};
	vector<int> integers(values.cbegin(), values.cend());
	ostream_iterator<int> output(cout, " ");
	
	cout << "Vector integers contain: ";
	copy(integers.cbegin(), integers.cend(), output);
	
	cout << "\nFirst element if integers: " << integers.front();
	cout << "\nLast element if integers: " << integers.back() << endl;
	
	integers[0] = 7;
	integers.at(2) = 10;
	
	integers.insert(integers.cbegin() + 1, 22);
	
	cout << "\nContent of integers after change: ";
	copy(integers.cbegin(), integers.cend(), output);
	
	try{
		cout << integers.at(100);
	}catch(out_of_range &ofr){
		cout << "\nException: " << ofr.what();
	}
	
	integers.erase(integers.cbegin());
	cout << "\nAfter erase first element: ";
	copy(integers.cbegin(), integers.cend(), output);
	
	integers.erase(integers.cbegin(), integers.cend());
	cout << "\nAfter erase all elements: " 
		<< (integers.empty() ? "is": "is not") << " empty\n";
		
	integers.insert(integers.begin(), values.begin(), values.end());
	cout << "\nContent of integers before clear: ";
	copy(integers.begin(), integers.end(), output);
	
	integers.clear();
	cout << "\nContent of integers after clear: " 
		<< (integers.empty() ? "is": "is not") << " empty\n";
}











