#include <iostream>
#include <array>
#include <list>
#include <iterator>
#include <algorithm>

#define SIZE 4
using namespace std;
template <typename T> void printList(const list<T> &listRef){
	if(listRef.empty()){
		cout << "List is empty";
	}else{
		ostream_iterator<int> output(cout, " ");
		copy(listRef.cbegin(), listRef.cend(), output);
	}
	cout << endl;
}


int main(){
	array<int, SIZE> ints = {2,6,4,8};
	list<int> values;
	list<int> otherValues;
	
	values.push_front(1);
	values.push_front(2);
	values.push_back(4);
	values.push_back(3);
	
	cout << "values contain: ";
	printList(values);
	cout << endl;
	
	otherValues.insert(otherValues.cbegin(), ints.begin(), ints.end());
	cout << "After insert, otherValues contains: ";
	printList(otherValues);
	cout << endl;
	
	values.splice(values.cend(), otherValues);
	cout << "After splice, values contains: ";
	printList(values);
	cout << "After splice, otherValues is: ";
	printList(otherValues);
	cout << endl;
	
	values.sort();
	cout << "Values after sorting contains: ";
	printList(values);
	cout << endl;
	
	otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
	otherValues.sort();
	cout << "After insert and sort, otherValues contain: ";
	printList(otherValues);
	cout << endl;
	
	
	
	values.merge(otherValues);
	cout << "After merge, values: ";
	printList(values);
	cout << "After merge, otherValues:  ";
	printList(otherValues);
	cout << endl;
	
	values.pop_front();
	values.pop_back();
	cout << "After pop_front and pop_back, values contains: ";
	printList(values);
	cout << endl;
	
	values.unique();
	cout << "After unique, values: "; printList(values);
	cout << endl;
	
	values.swap(otherValues);
	cout << "After swap, values: "; printList(values);
	cout << "After swap, otherValues: "; printList(otherValues);
	cout << endl;
	
	values.assign(otherValues.begin(), otherValues.end());
	cout << "After assign, values: "; printList(values);
	cout << "After assign, otherValues: "; printList(otherValues);
	cout << endl;
	
	values.merge(otherValues);
	cout << "After merge, values: ";
	printList(values);
	cout << "After merge, otherValues:  ";
	printList(otherValues);
	cout << endl;
	
	values.remove(4);
	cout << "After remove(4), values: "; printList(values);
}











