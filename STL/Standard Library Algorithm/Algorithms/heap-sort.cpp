#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;
#define SIZE 10

int main(){
	array<int, SIZE> init =  { 3, 100, 52, 77, 22, 31, 1, 98, 13, 40 };
	array<int, SIZE> a(init);
	ostream_iterator<int> output(cout, " ");
	
	cout << "array before make heap:\n";
	copy(a.begin(), a.end(), output);
// make_heap
	make_heap(a.begin(), a.end());
	
	cout << "\narray after make heap:\n";
	copy(a.begin(), a.end(), output);
// sort_heap	
	sort_heap(a.begin(), a.end());
	
	cout << "\narray after sort_heap:\n";
	copy(a.begin(), a.end(), output);
	
// push_heap, pop_heap
	vector<int> v;
	cout << "\n\nArray init contains:\n";
	copy(init.begin(), init.end(), output);
	
	for(int i = 0; i < SIZE; i++){
		v.push_back(init[i]);
		push_heap(v.begin(), v.end());
		cout << "\nv after push_heap(init[" << i << "]): ";
		copy(v.begin(), v.end(), output);
	}
	
	cout << "\n";
	for(size_t i = 0; i < v.size(); i++){
		pop_heap(v.begin(), v.end() - i);
		cout <<"\nv after pop_heap(v[" << i<<"]): ";
		copy(v.begin(), v.end(), output);
	}
}
