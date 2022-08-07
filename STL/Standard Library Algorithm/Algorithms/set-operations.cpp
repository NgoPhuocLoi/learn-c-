#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;
#define SIZE1 10
#define SIZE2 5
#define SIZE3 20


int main(){
	array<int, SIZE1> a1 = {1,2,3,4,5,6,7,8,9,10};
	array<int, SIZE2> a2 = {4,5,6,7,8};
	array<int, SIZE2> a3 = {4,5,6,11,15};
	ostream_iterator<int> output(cout, " ");
	
	cout << "a1 contains: \n";
	copy(a1.begin(), a1.end(), output);
	cout << "\na2 contains: \n";
	copy(a2.begin(), a2.end(), output);
	cout << "\na3 contains: \n";
	copy(a3.begin(), a3.end(), output);
	
// includes
	cout<<"\n\n====INCLUDES====";
	if(includes(a1.begin(), a1.end(), a2.begin(), a2.end()))
		cout << "\na1 includes a2";
	else
		cout << "\na1 does not include a2";
		
	if(includes(a1.begin(), a1.end(), a3.begin(), a3.end()))
		cout << "\na1 includes a3";
	else
		cout << "\na1 does not include a3";

// set_difference
	cout<<"\n\n====DIFFERENCE====";
	array<int, SIZE1> difference;
	auto result = set_difference(a1.begin(), a1.end(), a2.begin(), a2.end(), difference.begin());
	cout << "\nset_difference of a1 and a2 is:\n";
	copy(difference.begin(), result, output);
	result = set_difference(a1.begin(), a1.end(), a3.begin(), a3.end(), difference.begin());
	cout << "\nset_difference of a1 and a3 is:\n";
	copy(difference.begin(), result, output);

// set_intersection
	cout<<"\n\n====INTERSECTION====";
	array<int, SIZE1> intersection;
	result = set_intersection(a1.begin(), a1.end(), a2.begin(), a2.end(), intersection.begin());
	cout << "\nset_intersection of a1 and a2 is:\n";
	copy(intersection.begin(), result, output);
	result = set_intersection(a1.begin(), a1.end(), a3.begin(), a3.end(), intersection.begin());
	cout << "\nset_intersection of a1 and a3 is:\n";
	copy(intersection.begin(), result, output);
	
// set_symmetric_difference
	cout<<"\n\n====SYMMETRIC DIFFERENCE====";
	array<int, SIZE1> symmetric_difference;
	result = set_symmetric_difference(a1.begin(), a1.end(), a2.begin(), a2.end(), symmetric_difference.begin());
	cout << "\nset_symmetric_difference of a1 and a2 is:\n";
	copy(symmetric_difference.begin(), result, output);
	result = set_symmetric_difference(a1.begin(), a1.end(), a3.begin(), a3.end(), symmetric_difference.begin());
	cout << "\nset_symmetric_difference of a1 and a3 is:\n";
	copy(symmetric_difference.begin(), result, output);
	
// set_union
	cout<<"\n\n====UNION====";
	array<int, SIZE3> unionSet;
	result = set_union(a1.begin(), a1.end(), a2.begin(), a2.end(), unionSet.begin());
	cout << "\nset_union of a1 and a2 is:\n";
	copy(unionSet.begin(), result, output);
	result = set_union(a1.begin(), a1.end(), a3.begin(), a3.end(), unionSet.begin());
	cout << "\nset_union of a1 and a3 is:\n";
	copy(unionSet.begin(), result, output);
}
