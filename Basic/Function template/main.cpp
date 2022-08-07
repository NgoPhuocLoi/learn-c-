#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
T square(T n){
	return n*n;
}

int main(){
	cout << sizeof(square(12.2));
	cout << square(3);
	puts("\nRun!");
}
