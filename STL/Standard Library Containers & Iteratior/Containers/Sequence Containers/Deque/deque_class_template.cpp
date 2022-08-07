#include <iostream>
#include <iterator>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	deque<double> values;
	ostream_iterator<double> output(cout, " ");
	
	values.push_front(1);
	values.push_back(2);
	values.push_front(100);
	
	cout << "values contain: ";
	for(int i = 0; i < values.size(); ++i){
		cout << values[i] << " ";
	}
	
	values.assign({3,4,6, 9 ,10});
	cout << "\nValue after assign: ";
	copy(values.cbegin(), values.cend(), output);
}
