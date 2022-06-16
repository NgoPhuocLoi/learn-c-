#include <iostream>

using namespace std;

template <class T>
T square(T n){
	return n*n;
}

int main(){
	cout << sizeof(square(12.2));
	
	puts("\nRun!");
}
