#include <iostream>
#include <algorithm>
#include <numeric> // accumulate
#include <iterator>
#include <array> 
#include <cstdlib> // rand, srand
#include <ctime>

using namespace std;
#define SIZE 10

int myrandom(int i){
	return rand() % i;
}

bool greater9(int i){
	return i > 9;
}

int myOperation(int x, int y){
	return x - y;
}

void outputSquare(int x){
	cout << x*x << " ";
}

int calculateCube(int x){
	return x*x*x;
}

int main(){
	srand(time(0));
	array<int, SIZE> a1 = {1,2,3,4,5,6,7,8,9,10};
	ostream_iterator<int> output(cout, " ");

// random_shuffle
	cout << "====RANDOM_SUFFLE====\n";
	cout << "a1 before shuffle:\n";
	copy(a1.begin(), a1.end(), output);
	
	// random_shuffle version 1
	random_shuffle(a1.begin(), a1.end());
	cout << "\na1 after first shuffling:\n";
	copy(a1.begin(), a1.end(), output);
	// random_shuffle version 2
	random_shuffle(a1.begin(), a1.end(), myrandom);
	cout << "\na1 after second shuffling:\n";
	copy(a1.begin(), a1.end(), output);

// count, count_if
	cout << "\n\n====COUNT, COUNT_IF====";
	array<int, SIZE> a2 =  { 100, 2, 8, 1, 50, 3, 8, 8, 9, 10 };
	cout << "\na2 contains:\n";
	copy(a2.begin(), a2.end(), output);
	
	int result = count(a2.begin(), a2.end(), 8);
	cout << "\nNumber of elements matching 8: " << result;
	
	result = count_if(a2.begin(), a2.end(), greater9);
	cout << "\nNumber of elements greater than 9: " << result;
	
// min_element, max_element, minmax_element
	cout << "\n\n====MIN, MAX====";
	cout << "\nMinimum element of a2: " << *(min_element(a2.begin(), a2.end()));
	cout << "\nMaximum element of a2: " << *(max_element(a2.begin(), a2.end()));
	
	auto minAndMax = minmax_element(a2.begin(), a2.end());
	cout << "\nThe minimum and maximum element of a2 is " << *(minAndMax.first) 
		<< "(at position " << (minAndMax.first - a2.begin()) << ")"
		<< " and " << *(minAndMax.second) << "(at position " << (minAndMax.second - a2.begin())
		 << ")"<< " respectively.";

// accumulate
	cout << "\n\n====ACCUMULATE====";
	// version 1
	cout << "\nTotal of the elements in a1: " << accumulate(a1.begin(), a1.end(), 0);
	// version 2
	cout << "\n100 - total(a1): " << accumulate(a1.begin(), a1.end(), 100, myOperation);
	
// for_each, transform
	cout << "\n\n====FOR_EACH, TRANSFORM====";
	cout << "\nThe square of every integer in a1:\n";
	for_each(a1.begin(), a1.end(), outputSquare);
	
	// transform version 1
	array<int, SIZE> cubes;
	transform(a1.begin(), a1.end(), cubes.begin(), calculateCube); // third params can equal the first
	cout << "\nThe cube of every integer in a1:\n";
	copy(cubes.begin(), cubes.end(), output);
	
	// transform version 2
	// calculate a1[i] - a2[i] and store to a3[i];
	array<int, SIZE> a3;
	transform(a1.begin(), a1.end(), a2.begin(), a3.begin(), myOperation);
	cout << "\na3 after tranform (a3[i] = a1[i] - a2[i]):\n";
	copy(a3.begin(), a3.end(), output);
}
