#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>

using namespace std;

bool myCompare(int x, int y){
	return x > y;
}

int main(){
	array<int, 4> a = {1,2,3,4};
	array<int, 5> a2 = {1,4,3,11,2};
	ostream_iterator<int> output(cout, " ");
	
// using lambda expression with for_each (as function pointer | function object)
	for_each(a.begin(), a.end(), [](int i){cout << i*i << " ";});
	// modify local variables
	int sum = 0;
	for_each(a.begin(), a.end(), [&sum](int i){sum += i;});
	cout << "\nThe sum is: " << sum << endl;

// using with sort
	cout << "a2 before sorting:\n";
	copy(a2.begin(), a2.end(), output);
	sort(a2.begin(), a2.end(), [](int x, int y){return x > y;});
	cout << "\na2 after sorting:\n";
	copy(a2.begin(), a2.end(), output);
	cout << endl;
	
// can assign to variable
	auto myLambda = [](int i){return i*i;};
	cout << "myLambda(10) = " << myLambda(10);
}
