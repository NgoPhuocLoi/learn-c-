#include <iostream>
#include <algorithm>
#include <iterator>
#include <array>
#include <string>

using namespace std;

char nextLetter(){
	static char letter = 'A';
	return letter++;
}



int main(){
	array<char, 10> chars;
	ostream_iterator<char> output(cout, " ");
	
	fill(chars.begin(), chars.end(), '5');
	cout << "chars after filling '5': \n";
	copy(chars.begin(), chars.end(), output);
	
	
	fill_n(chars.begin(), 5, 'A');
	cout << "\nchars after filling first five element with 'A': \n";
	copy(chars.begin(), chars.end(), output);
	
	generate(chars.begin(), chars.end(), nextLetter);
	cout << "\nchars after generate: \n";
	copy(chars.begin(), chars.end(), output);
	
	generate_n(chars.begin(), 5, nextLetter);
	cout << "\nchars after generate first 5 elements: \n";
	copy(chars.begin(), chars.end(), output);
	cout << "\nRun";
}
